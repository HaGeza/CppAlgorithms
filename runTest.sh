#!/bin/bash

cd build # TODO: Use variable for build directory name

# Build
cmake ..
make

# Test
cd test # TODO: Use variable for test directory name
ctest

# Return to start dir
cd ../..