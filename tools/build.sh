#!/bin/bash

SCRIPT_PATH="${BASH_SOURCE:-$0}"
SCRIPT_DIR="$(dirname "${SCRIPT_PATH}")"

cd "${SCRIPT_DIR}/.." || exit
cmake -S . -B build
cd build || exit
cmake --build . --target client --config Debug
