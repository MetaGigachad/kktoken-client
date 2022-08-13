#!/bin/bash

cd "$1" || exit
cmake -S . -B build
cd build || exit
cmake --build . --target client --config Debug
