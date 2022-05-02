#!/bin/bash

# install premake
./install_premake.sh

# create 3rd party library directory if it doesn't exist
mkdir -p lib
cd lib

# clone eigen if it isn't already there
if [ ! -d "./eigen/" ]; then
  git clone --branch 3.4 https://gitlab.com/libeigen/eigen.git
fi
cd ..