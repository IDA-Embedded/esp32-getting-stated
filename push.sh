#!/bin/bash
GIT_MSG=$1
if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    exit -1
fi

set -e # exit on error

#make

git add .
git commit -m "$GIT_MSG"
git push

sleep 3

sh ./tools/jenkins/callJenkins.sh
