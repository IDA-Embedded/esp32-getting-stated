#!/bin/bash

# bash script to install the 3rd part requirements for the library
# 
# we want basic analysis tools : clang, lizard, cppcheck and other


sudo apt -y update
sudo apt -y upgrade

# install prerequisites
echo "installing prerequisites" 
# install cmake 
python3 -m pip install cmake
sudo apt-get install cmake-qt-gui
#install ninja
sudo apt-get install -y ninja-build

# basic requirements for CI/CD
sudo apt install doxygen cppcheck gcovr lcov clang-format clang-tidy clang-tools graphviz 

# code complexity analysis
python3 -m pip install lizard

sudo apt-get install git wget flex bison gperf python3 python3-pip python3-setuptools ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
echo "done ..."
########################################################################################################

sudo chmod +x ./tools/*
