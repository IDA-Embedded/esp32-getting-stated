#!/bin/bash
set -e # exit on error
PROJECT_NAME=$1
ARTIFACT_PATH=$2

PROJECT_ARTIFACT_FOLDER=${ARTIFACT_PATH}${PROJECT_NAME}

echo "Publiching Artifact to ${PROJECT_ARTIFACT_FOLDER} .... ";

[ ! -d "${PROJECT_ARTIFACT_FOLDER}" ] && mkdir ${PROJECT_ARTIFACT_FOLDER} 

GIT_MSG=$(git rev-parse --short HEAD)

cp ./build/artifact.zip ${PROJECT_ARTIFACT_FOLDER} 
rm ./build/artifact.zip

cd ${ARTIFACT_PATH}
git add .
git commit -m "Pushing artifact ${PROJECT_NAME} git vers $GIT_MSG"
git push