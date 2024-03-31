NAME := eqemu-server
VERSION ?= 0.0.1

DOCKER_ARGS := --rm  --name ${NAME} -v ${PWD}:/src -w /src ${NAME}


# git remote add eqemu git@github.com:EQEmu/server.git
# git fetch eqemu
# git checkout -b eqemu-master eqemu/master
# git branch xackery/2024-03-18 # create a new branch based on latest main
# git checkout xackery/2024-03-18 # switch to the new branch
# git merge eqemu-master xackery/2024-03-18 # merge all the changes on my eqemu-master branch to xackery/may-latest
# git remote rm eqemu # remove the eqemu remote
# git branch -d eqemu-master # remove the eqemu-master branch locally

# Run 'ninja' in build directory
.PHONY: build
build:
	@if [ ! -d "build$$BUILD_SUFFIX" ]; then \
		make cmake; \
	fi

	@cd build$$BUILD_SUFFIX && cmake --build . --config Release --target all --

# Run 'cmake' in build directory
.PHONY: cmake
cmake:
	mkdir -p build$$BUILD_SUFFIX
	@cd build$$BUILD_SUFFIX && cmake -DEQEMU_BUILD_LOGIN=ON \
			-DEQEMU_BUILD_TESTS=ON \
			-DCMAKE_CXX_COMPILER_LAUNCHER=ccache -G Ninja ..

clean:
	rm -rf build

# Run 'cmake' in ubuntu docker container
docker-cmake: docker-image-build
	git submodule update --init --recursive
	docker run ${DOCKER_ARGS} make cmake

# Run 'ninja' in ubuntu docker container
docker-build: docker-image-build
	docker run ${DOCKER_ARGS} make build

# Build image if it doesn't exist
docker-image-build:
	@echo "Docker image not found. Building..."
	cd .devcontainer && docker build -f Dockerfile.ubuntu.dev -t ${NAME} .

docker-clean: clean

# CICD triggers this
set-version:
	sed -i 's/#define VERSION ".*/#define VERSION "$(VERSION)-$(shell git show --format=%h -s)"/g' common/version.h
	@echo "VERSION=${VERSION}-$(shell git show --format=%h -s)" >> $$GITHUB_ENV


MARIADB_VERSION := 11.2.2
MARIADB_FOLDER := mariadb-${MARIADB_VERSION}-linux-systemd-x86_64
OS := $(shell uname -s)

.PHONY: prep
prep:
	@echo "Preparing build/bin for usage..."
	cp -R -u -p base/eqemu_config.json build/bin/eqemu_config.json
	cp -R -u -p base/login.json build/bin/login.json
	cp -R -u -p loginserver/login_util/* build/bin/assets/patches/
	mkdir -p build/bin/assets
	cp -R -u -p utils/patches build/bin/assets/
	-unlink build/bin/lua_modules
	cd build/bin && ln -s quests/lua_modules lua_modules
	-unlink build/bin/mods
	cd build/bin && ln -s quests/mods mods
	-unlink build/bin/maps
	cd build/bin && ln -s ../../base/maps maps
	mkdir -p build/bin/logs
	mkdir -p build/bin/shared
	@echo "Eqemu is prepared"

maps:
	@echo "Downloading maps..."
	@mkdir -p base/maps
	@cd base/maps && wget -nc https://github.com/Akkadius/eqemu-maps/archive/refs/heads/master.zip
	@cd base/maps && unzip -o master.zip
	@cd base/maps && mv eqemu-maps-master/* .
	@cd base/maps && rm -rf eqemu-maps-master
	@echo "Maps downloaded."

# Runs tests
.PHONY: test
test:
	cd build/bin && ./tests

# Runs login binary
.PHONY: login
login:
	cd build/bin && ./loginserver

# Runs shared_memory binary
.PHONY: shared
shared:
	cd build/bin && ./shared_memory

# Runs zone binary
.PHONY: zone
zone:
	@-rm build/bin/logs/zone/zone*.log
	cd build/bin && ./zone

# Runs world binary
.PHONY: world
world:
	@-rm build/bin/logs/world*.log
	cd build/bin && ./world

# Runs ucs binary
.PHONY: ucs
ucs:
	@-rm build/bin/logs/ucs*.log
	cd build/bin && ./ucs

# Runs queryserv binary
.PHONY: queryserv
queryserv:
	@-rm build/bin/logs/query_server*.log
	cd build/bin && ./queryserv

# Start mariaDB standalone
.PHONY: mariadb
mariadb:
	@sudo service mariadb start

# Backs up the database
.PHONY: backup-db
backup-db:
	@echo "Backing up the database and zipping it..."
	@-rm -rf build/bin/db/backup
	@-mkdir -p build/bin/db/backup
	cd build/bin/db/${MARIADB_FOLDER}/bin && ./mariabackup --defaults-file=${PWD}/build/bin/db/my.cnf --backup --user=${USER} --socket=${PWD}//var/run/mysqld/mysqld.sock --target-dir=${PWD}/build/bin/db/backup
	cd build/bin/db && tar -czvf backup.tar.gz backup
	@-rm -rf build/bin/db/backup
	@echo "Backup complete. The file is located at build/bin/db/backup.tar.gz"

# Restores the database
.PHONY: restore-db
restore-db:
	@echo "Restoring the database from backup..."
	@-mkdir -p build/bin/db/backup
	cd build/bin/db && tar -xf backup.tar.gz
	cd build/bin/db/${MARIADB_FOLDER}/bin && ./mariabackup --defaults-file=${PWD}/build/bin/db/my.cnf --prepare --user=${USER} --socket=${PWD}//var/run/mysqld/mysqld.sock --target-dir=${PWD}/build/bin/db/backup
	cd build/bin/db && rm -rf backup.tar.gz
	@echo "Restore complete."

# Initializes a standalone copy of mariadb-server
.PHONY: init-db
init-mariadb:
	@echo "Initializing a standalone copy of mariadb-server..."
	@-mkdir -p build/bin/db
	@-sudo service mariadb start
	@# old way, kept for history reasons for portable edition
	@#cd build/bin/db && wget -nc https://mirrors.xtom.com/mariadb//mariadb-${MARIADB_VERSION}/bintar-linux-systemd-x86_64/${MARIADB_FOLDER}.tar.gz
	@#cd build/bin/db && pv ${MARIADB_FOLDER}.tar.gz | tar -xz
	@#cp -R -u -p base/my.cnf build/bin/db/my.cnf
	@#cd build/bin/db/${MARIADB_FOLDER}/scripts && ./mariadb-install-db --defaults-file=${PWD}/build/bin/db/my.cnf --datadir=${PWD}/build/bin/db/data --basedir=${PWD}/build/bin/db/${MARIADB_FOLDER}
	@#cd build/bin/db/${MARIADB_FOLDER}/bin && ./mysqld_safe --initialize-insecure --datadir=${PWD}/build/bin/db/data --defaults-file=${PWD}/build/bin/db/my.cnf
	@#echo "MariaDB is now initialized. Use 'make mariadb' to run it."
	@echo "MariaDB is now initialized."


.PHONY: inject-mariadb
inject-mariadb:
	-sudo service mariadb start
	-mkdir -p base
	-sudo mariadb -e 'DROP DATABASE IF EXISTS peq;'
	-sudo mariadb -e 'CREATE DATABASE peq;'
	-sudo mariadb -e "CREATE USER 'peq'@'127.0.0.1' IDENTIFIED BY 'peqpass';"
	-sudo mariadb -e "GRANT ALL PRIVILEGES ON *.* TO 'peq'@'127.0.0.1';"
ifeq (,$(wildcard base/db/db.sql.zip))
	@echo "base/db.sql.zip not found. Please download the database from https://www.eqemulator.org/downloads/downloads.php?do=file&id=1"
	wget -nc https://db.projecteq.net/api/v1/dump/archive/peq-1710835223.zip -O base/db.sql.zip
endif
	-cd base/db && sudo service mariadb start && unzip db.sql.zip
	@echo "Sourcing db may take a while, please wait..."
	@cd base/db/peq-dump && sudo mariadb --database peq -e "source create_all_tables.sql"
	@echo "MariaDB is now injected."

.PHONY: gm-%
gm-%:
	sudo mariadb --database peq -e "UPDATE account SET status=255 WHERE name = '$*';"
	@echo "Account $* is now a GM. /camp to have it go into effect."

depends:
	sudo apt install graphviz pip time
	pip3 install graphviz
	mkdir -p build/depends
	@if [ ! -f "build/depends/dependency_graph.py" ]; then \
		wget https://raw.githubusercontent.com/pvigier/dependency-graph/master/dependency_graph.py -O build/depends/dependency_graph.py; \
	fi
	@echo "Generating dependency graphs (This may take a while)..."
	@echo "Login..."
	time python3 build/depends/dependency_graph.py -f png login build/depends/login.dot
	@echo "World..."
	time python3 build/depends/dependency_graph.py -f png world build/depends/world.dot
	@echo "Zone..."
	time python3 build/depends/dependency_graph.py -f png zone build/depends/zone.dot
	@echo "Common..."
	time python3 build/depends/dependency_graph.py -f png common build/depends/common.dot

inject-all:
	make inject-aa
	make inject-rule
	make inject-zone
	make inject-content-flags
	make inject-npc-types

inject-aa:
	cd base/expansion && sudo mariadb --database peq -e "source aa.sql"

inject-rule:
	cd base/expansion && sudo mariadb --database peq -e "source rules.sql"

inject-zone:
	cd base/expansion && sudo mariadb --database peq -e "source zone.sql"

inject-content-flags:
	cd base/expansion && sudo mariadb --database peq -e "source content_flags.sql"

inject-npc-types:
	cd base/expansion && sudo mariadb --database peq -e "source npc_types.sql"