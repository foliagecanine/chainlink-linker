# chainlink-linker
![chainlink-linker icon](https://github.com/foliagecanine/chainlink-linker/raw/master/res/chainlink.png){:height="50%" width="50%"}  
An easy GUI to create symlinks.

See [LICENSE](https://github.com/foliagecanine/chainlink-linker/blob/master/LICENSE) for licensing information.

## Build instructions
First, install necessary packages (all installations will be for Debian-based systems):

`sudo apt-get install gcc libgtk-3-dev`

Then run

`make`

to make the binary. It will appear as chainlink in the root build folder.

## Install instructions

You can run

`sudo make install`

to install just the binary OR run

`sudo make install-desktop`

to install the binary and an icon.

## Uninstall

Run

`sudo make uninstall`

to uninstall the binary only OR

run

`sudo make uninstall-desktop`

to uninstall the binary and icon.
