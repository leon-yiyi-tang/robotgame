#!/bin/bash


set -e

mkdir build-linux
cd build-linux
cmake ..
cmake --build .
ctest

