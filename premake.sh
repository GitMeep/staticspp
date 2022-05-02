#!/bin/bash

# Download premake5 if it isn't present
if [ ! -f "./premake/premake5" ]; then
  echo -e "\033[0;33mPremake not found, downloading.\033[0m"
  mkdir -p premake
  cd premake
  wget https://github.com/premake/premake-core/releases/download/v5.0.0-beta1/premake-5.0.0-beta1-linux.tar.gz
  tar -xf premake-5.0.0-beta1-linux.tar.gz
  rm premake-5.0.0-beta1-linux.tar.gz
fi

./premake/premake5 gmake2