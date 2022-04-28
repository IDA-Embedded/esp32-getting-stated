#!/bin/bash

# simple bash script to install esp32 idf


# if the .espressif folder exists in the home directory
# we assume that the installation has been completed, and there for exits the script
if [[ -d "$HOME/.espressif" ]]
then
    echo "$HOME/.espressif exists on your filesystem, aborting install."
    exit 0
fi


sh ./tools/install_requirements.sh

# Save current working directory
cwd=$(pwd)

echo "cloning repo  <version 4.3.1>..."

mkdir -p $HOME/esp
cd $HOME/esp
git clone --recursive https://github.com/espressif/esp-idf.git -b v4.3.1 

echo "done ..."

echo "installing sdk"
cd $HOME/esp/esp-idf
./install.sh esp32
echo "done ..."

echo ". $HOME/esp/esp-idf/export.sh" >> $HOME/.profile
cd "$cwd"
