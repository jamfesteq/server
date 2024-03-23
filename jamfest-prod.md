This is just self notes for how prod was configured.

## Inject DB

Do each command one by one and ensure all is happy

sudo apt update
sudo apt upgrade

(optional, but suggested in case you lose session)
screen

sudo apt install unzip mariadb-server
sudo service mariadb start
sudo mariadb -e 'DROP DATABASE IF EXISTS peq;'
sudo mariadb -e 'CREATE DATABASE peq;'

(obviously, change peqpass)
sudo mariadb -e "CREATE USER 'peq'@'127.0.0.1' IDENTIFIED BY 'peqpass';"

sudo mariadb -e "GRANT ALL PRIVILEGES ON *.* TO 'peq'@'127.0.0.1';"
cd ~
wget -nc https://db.projecteq.net/api/v1/dump/archive/peq-1710835223.zip -O db.sql.zip
unzip db.sql.zip
cd peq-dump
sudo mariadb --database peq -e "source create_all_tables.sql"
cd ..
rm -rf peq-dump
rm db.sql.zip

## Initial Setup

sudo mkdir -p /eqemu
sudo chown $USER -R /eqemu
sudo chgrp $USER -R /eqemu

(One time, for config copying)
scp z420:/src/jamfesteq/server/base/eqemu_config.json 20.171.254.171:/eqemu
(Edited config with WAN ip and various settings)

(One time, copy assets)
ssh -t 20.171.254.171 "cd /eqemu && mkdir -p assets/patches"
scp z420:/src/jamfesteq/server/loginserver/login_util/* 20.171.154.171:/eqemu/assets/patches
scp z420:/src/jamfesteq/server/utils/patches/* 20.171.154.171:/eqemu/assets/patches

(One time, symlink)
ssh -t 20.171.254.171 "cd /eqemu && ln -s quests/lua_modules lua_modules"
ssh -t 20.171.254.171 "cd /eqemu && ln -s quests/mods mods"
ssh -t 20.171.254.171 "cd /eqemu && mkdir -p logs"
ssh -t 20.171.254.171 "cd /eqemu && mkdir -p shared"


## Copy binaries

Likely will be reused later for new binary copies

```
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && rm jamfesteq.zip"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip zone"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip world"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip shared_memory"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip *.a"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip queryserv"
ssh -t z420 "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip ucs"

ssh -t 20.171.254.171 "cd /eqemu && mv jamfesteq.zip jamfesteq.zip.old"
scp z420:/src/jamfesteq/server/build/bin/jamfesteq.zip 20.171.254.171:/eqemu
ssh -t 20.171.254.171 "cd /eqemu && unzip jamfesteq.zip"
```

## Docker setup (not used)

sudo apt-get update
sudo apt-get install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/debian/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/debian \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update

sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

sudo docker run hello-world

sudo groupadd docker

sudo usermod -aG docker $USER

Now relog session

docker run hello-world

