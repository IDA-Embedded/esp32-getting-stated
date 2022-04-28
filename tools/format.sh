#!/bin/bash

# bash script to apply clang-format to the entire codebase
# we are excluding */buld folder aswell as */ThirdPartAPI as we do not want to make any changes to these files.
find target -type d \( -path */Embedded_CPP_Library \) -prune -type f  -o -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp \
| xargs clang-format -style=file -i -fallback-style=none

