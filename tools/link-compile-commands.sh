#!/bin/bash

SCRIPT_PATH="${BASH_SOURCE:-$0}"
SCRIPT_DIR="$(dirname "${SCRIPT_PATH}")"

cd "${SCRIPT_DIR}/.." || exit
ln -srv build/compile_commands.json .
