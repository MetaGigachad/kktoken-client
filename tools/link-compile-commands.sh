#!/bin/bash

cd "$1" || exit
ln -srv build/compile_commands.json .
