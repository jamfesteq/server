This is just self notes for how prod was configured.

debian 12! (to mirror the dev container)

## Configuration

My dev box is called mint-stick

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

on local box:

scp mint-stick:/src/jamfesteq/server/base/eqemu_config.json jf:/eqemu
nano eqemu_config remotely
- delete localaddress
- change address to WAN
- generate key
- change longname
- put in db password

(One time, copy assets)
ssh -t jf "cd /eqemu && mkdir -p assets/patches"
scp mint-stick:/src/jamfesteq/server/loginserver/login_util/* jf:/eqemu/assets/patches
scp mint-stick:/src/jamfesteq/server/utils/patches/* jf:/eqemu/assets/patches

(One time, symlink)
ssh -t jf "cd /eqemu && ln -s quests/lua_modules lua_modules"
ssh -t jf "cd /eqemu && ln -s quests/mods mods"
ssh -t jf "cd /eqemu && mkdir -p logs"
ssh -t jf "cd /eqemu && mkdir -p shared"

## Clone repos

on remote box:

[Make a pat](https://github.com/settings/personal-access-tokens/new)
- call it jamfesteq-prod-git
- expiration: 01-01-2025 (next year)
- resource owner, jamfesteq
- only select repositories, jamfesteq/quests
- repository permissions, contents, read only
- add select repositories, jamfesteq/web
- repository permissions, contents, read only
- add select repositories, jamfesteq/server
- copy pat token
git clone https://pattoken@github.com/jamfesteq/quests.git
git clone https://pattoken@github.com/jamfesteq/web.git
git clone https://github.com/Akkadius/eqemu-maps.git maps
git clone https://pattoken@github.com/jamfesteq/server.git
- NOTE that while we do clone server, we are just using it for the sql tweaks


## Copy binaries

on local box:
Likely will be reused later for new binary copies

```sh
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && rm -f jamfesteq.zip"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip zone"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip world"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip shared_memory"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip *.a"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip queryserv"
ssh -t mint-stick "cd /src/jamfesteq/server/build/bin/ && zip -r jamfesteq.zip ucs"
ssh -t jf "cd /eqemu && mv jamfesteq.zip jamfesteq.zip.old"
scp mint-stick:/src/jamfesteq/server/build/bin/jamfesteq.zip jf:/eqemu
```

ssh -t jf "cd /eqemu && unzip jamfesteq.zip"


## Initial run

on remote box in /eqemu:

./shared_memory

./zone
see if success
ctrl+a+c
./world
see if success
log in
make yourself a gm
sudo mariadb --database peq -e "UPDATE account SET status=255 WHERE name = 'xackery';"

### talkeq
wget https://github.com/xackery/talkeq/releases/latest/download/talkeq-linux
mv talkeq-linux talkeq
chmod +x talkeq
./talkeq
nano talkeq
- do lots of edits

### githubeq

wget https://github.com/xackery/githubeq/releases/latest/download/githubeq-linux
mv githubeq-linux githubeq
chmod +x githubeq
killall githubeq
./githubeq
- generate a pat simialar to githubeq's instructions
nano githubeq.conf
- put pat, repo, user in conf
./githubeq
go in game and type #issue testing issues
see if it generates an issue

### overseer

wget https://github.com/xackery/overseer/releases/latest/download/overseer-linux.zip
unzip overseer-linux.zip
rm overseer-linux.zip update verify install diagnose
./overseer
- classic
- no, no, no, no, 1
ctrl+c exit overseer
nano overseer.ini
- bin_path = /eqemu/
- server_path = /eqemu/

./overseer
go in game and type #issue testing issues
see if it generates an issue

### webhook

wget https://github.com/xackery/webhook/releases/latest/download/webhook-linux -O webhook
chmod +x webhook
./webhook
nano webhook.conf
- change event1 to web
	- copy paste webhook from discord
	- create a webhook to server forwarding port 3000

### telleq

wget https://github.com/xackery/telleq/releases/latest/download/telleq-linux -O telleq
chmod +x telleq
./telleq

### tinywebeq

wget https://github.com/xackery/tinywebeq/releases/latest/download/tinywebeq-linux -O tinywebeq
chmod +x tinywebeq
./tinywebeq

### Bumping Expansions

- Go to base/expansion/ and edit every .sql file.
- On the top of each file, you'll see a source 0-foo/ for each expansion. Uncomment each one applicable.
- Run `make inject-all`

- Go to eqemupatcher and edit the Makefile, changing the expansion variable to your new expansion value.


