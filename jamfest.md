## Jamfest Dev Box Setup!

1. Install [Docker](https://www.docker.com/products/docker-desktop)
1. Install [VSCode](https://code.visualstudio.com/)

## Setup 1.1: Inside a dev container (Recommended over Setup 1.2)

This is recommended because you get autocomplete, debugging, and other features with no setup.

1. Install the [Remote - Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension for VSCode
1. Clone this repository
1. Open the repository in VSCode
1. Click on the green button in the bottom left corner of vscode and select "Reopen in Container"
1. Wait for the container to build and start
1. Open a terminal in VSCode (ctrl+~)
1. Run `git submodule update --init --recursive` to pull in submodules
1. Use the build link on the bottom status bar, then select the GCC bottom option, or:
	1. Alternatively, run `make cmake` to configure environment.
	1. Follow this with `make build` command after.
1. Verify in your `build/bin/` folder that zone, world, etc exist

## Setup 1.2 (Alternative): Docker makefiles

This is an alternative that is less integrated with VSCode, but works for just building binaries. Because it uses Makefiles, in windows you'll need to use WSL2 or a Linux VM to run the commands

1. Open a terminal in VSCode (ctrl+~) or in your preferred terminal
1. Run `make docker-cmake` to configure environment
1. Run `make docker-build` to build the project

## Setup 2: Inject the database

1. Open a terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make inject-mariadb` to get a fresh peq snapshot from base
1. If using setup 1.1 (dev container), run heidi or your preferred sql client to connect with the settings: 127.0.0.1:3306, peq, peq, peqpass. You should see all tables populated

## Setup 3: Clone quests

1. Start a new vscode window, and git clone the quests folder into build/bin/quests

## Setup 4: Prep the environment

1. Open a terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make prep` to copy the required files to the build directory. This can be ran multiple times to "reset" the environment
1. Navigate to build/bin/eqemu_config.json and edit the lines `10.0.0.10` to your LAN ip, e.g. 192.168.1.5, if this is incorrect, at server select you'll just "freeze connecting" until timeout
1. Inside build/bin/eqemu_config.json edit the server name from `Jamfest Devbox` to `Jamfest MyName Devbox`, replacing MyName with your user name

## Setup 5: Add expansion rules

This is only needed if you are wanting jamfest customizations.

1. Open a new terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make inject-all`
1. This applies zone, rules, aas.


## Setup 6: Run shared memory

1. Open a terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make shared`. On success, it should return to the terminal at end
1. Above should only need to be ran once, or if you modify items, skill caps, spells, and other expansion tweaks, it may need to be ran again while the server is fully shut down

## Setup 7: Run world

1. Open a terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make world`. On success, it should be idle and not return to an empty prompt

## Setup 8: Run zone

1. Open a new terminal in VSCode (ctrl+~) or your preferred terminal
1. Run `make zone`. On success, it should be idle. If you switch back to world, you should see an event about zone connecting

## Setup 9: Log in and set yourself GM

1. Using a rof2 client where eqhost.txt is set to projecteq's login will make your debox server appear under `[D] Jamfest MyName Devbox`
1. When you first log in, the world console should say like "SetOnline Online Status [foo] (1) status [Online]
1. You can run `make gm-foo` to update your status to 255, replacing foo with your name


## Setup 10: Optional, get maps

Maps are a big download so unless you care about navmesh, water, los testing, this can be skipped.

1. Simply run `make maps`. This will download maps to base/maps, and the make prep command you ran earlier symlinks it.


## Debugging

You can optionally debug by attaching via gdb to the running processes. This is only recommended if you are familiar with gdb and debugging in general

1. Add breakpoints in zone or world that you want to debug
1. Press CTRL+SHIFT+D or the debug icon on left pane, and select a (gdb) [processType] for what you want to debug
1. When your code reaches said break point, you will get a call stack and variable dump on left
1. While the break point is triggered, all code is frozen, so a connection client will slowly disconnect if you're not quick to resume the breakpoint


## Pulling master in

```
git remote add eqemu git@github.com:eqemu/server.git
git fetch eqemu
git checkout -b eqemu-master eqemu/master
git checkout main
git branch xackery/2024-04-18 # create a new branch based on latest main
git checkout xackery/2024-04-18 # switch to the new branch
git merge eqemu-master xackery/2024-04-18 --allow-unrelated-histories # merge all the changes
git remote rm eqemu # remove the eqemu-master remote ref
git branch -d eqemu-master # remove the eqemu-master branch locally
```