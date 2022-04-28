#!/bin/bash

# Argument 1 is the path to the directory containing the compile_commands.json file
OUTPUT_FOLDER=./docs/cppcheck

# bash script to apply clang-tidy to the entire codebase
# we are excluding */build folder aswell as */ThirdPartAPI and */test as we do not want to make any changes to these files.
find target -type d \( -path */Embedded_CPP_Library \) -prune -type f  -o -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp\
 | xargs cppcheck --enable=all --output-file=${OUTPUT_FOLDER}/output.html
