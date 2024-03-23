This is just self notes for how prod was configured.

debian 12! (to mirror the dev container)

## Configuration

My dev box is called z420

My prod box is aliased as jf

I build binaries on the dev box and push them to prod when ready

You'll need to set up these two destinations in /etc/hosts in linux with your ssh config properly aliasing to take full advantage of these instructions

## Inject DB

Do each command one by one and ensure all is happy

sudo apt update
sudo apt upgrade

(optional, but suggested in case you lose session)
screen
sudo apt install -y mariadb-server unzip git liblua5.1-0 gdb libjson-perl libio-stringy-perl

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
scp z420:/src/jamfesteq/server/base/eqemu_config.json jf:/eqemu
nano eqemu_config remotely
- delete localaddress
- change address to WAN
- generate key
- change longname
- put in db password

(One time, copy assets)
ssh -t jf "cd /eqemu && mkdir -p assets/patches"
scp z420:/src/jamfesteq/server/loginserver/login_util/* jf:/eqemu/assets/patches
scp z420:/src/jamfesteq/server/utils/patches/* jf:/eqemu/assets/patches

(One time, symlink)
ssh -t jf "cd /eqemu && ln -s quests/lua_modules lua_modules"
ssh -t jf "cd /eqemu && ln -s quests/mods mods"
ssh -t jf "cd /eqemu && mkdir -p logs"
ssh -t jf "cd /eqemu && mkdir -p shared"


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

ssh -t jf "cd /eqemu && mv jamfesteq.zip jamfesteq.zip.old"
scp z420:/src/jamfesteq/server/build/bin/jamfesteq.zip jf:/eqemu
ssh -t jf "cd /eqemu && unzip jamfesteq.zip"
```

## Initial run

./shared_memory
[Make a pat](https://github.com/settings/personal-access-tokens/new)
- call it jamfesteq-prod-git
- expiration: 01-01-2025 (next year)
- resource owner, jamfesteq
- only select repositories, jamfesteq/quests
- repository permissions, contents, read only
- add select repositories, jamfesteq/web
- repository permissions, contents, read only
- copy pat token
git clone https://pattoken@github.com/jamfesteq/quests.git
git clone https://pattoken@github.com/jamfesteq/web.git

./zone
see if success
ctrl+a+c
./world
see if success
log in
sudo mariadb --database peq -e "UPDATE account SET status=255 WHERE name = 'xackery';"

## Docker setup (not used)

This is more just self notes

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

