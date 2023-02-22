#!/bin/bash

mkdir -p build
cd build
mkdir -p release
cd release
cmake -DCMAKE_BUILD_TYPE=Release -Wno-deprecated -DBUILD_EXAMPLES=0 ../.. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cd ..
ln -s release/compile_commands.json .
