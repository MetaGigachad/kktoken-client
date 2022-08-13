#!/bin/bash

SCRIPT_PATH="${BASH_SOURCE:-$0}"
SCRIPT_DIR="$(dirname "${SCRIPT_PATH}")"

cd "${SCRIPT_DIR}/.." || exit

rm -r build
mkdir build
tools/get-dependencies.sh
tools/build.sh
tools/link-compile-commands.sh

printf "\n Project setup is completed!"
