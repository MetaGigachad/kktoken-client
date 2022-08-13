#!/bin/bash

SCRIPT_PATH="${BASH_SOURCE:-$0}"
SCRIPT_DIR="$(dirname "${SCRIPT_PATH}")"

cd "${SCRIPT_DIR}/../build" || exit
conan install .. --build=missing
