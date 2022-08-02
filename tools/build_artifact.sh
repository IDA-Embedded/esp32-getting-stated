#!/bin/bash
set -e # exit on error
[ ! -d "./build" ] && mkdir build

PROJECT_NAME=$1

echo "zipping folder "
ZIP_FOLDER=build/artifact

zip -q  -r $ZIP_FOLDER ./target/build/$PROJECT_NAME.elf

zip -q  -r $ZIP_FOLDER ./target/build/$PROJECT_NAME.bin

zip -q  -r $ZIP_FOLDER ./target/build/$PROJECT_NAME.map