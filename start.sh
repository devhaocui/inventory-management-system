#!/bin/bash

command_exists() {
    type "$1" &> /dev/null ;
}

if ! command_exists brew; then
    echo "Homebrew not found, installing..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

if ! brew list glfw &> /dev/null; then 
  echo "glfw not found, installing..."
  brew install glfw
fi

if ! command_exists cmake; then
  eecho "cmake not found, installing..."
  brew install cmake
fi
# run the executable to start the IMS program
./build/inv
