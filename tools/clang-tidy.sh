#!/bin/bash

# Argument 1 is the path to the directory containing the compile_commands.json file
BUILD_FOLDER=target/build/
OUTPUT_FOLDER=./docs/clang

# bash script to apply clang-tidy to the entire codebase
# we are excluding */build folder aswell as */ThirdPartAPI and */test as we do not want to make any changes to these files.
find target -not \( -path target/main/Components/esp32Cam_API -prune -o -path target/main/Components/image_conversions -prune -o -path target/build -prune \) \
-name \*.h* -o -name \*.c* | xargs clang-tidy -p $BUILD_FOLDER -o $OUTPUT_FOLDER

