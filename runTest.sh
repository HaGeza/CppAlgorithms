#!/bin/bash

cd build # TODO: Use variable for build directory name

# Build
cmake ..
make

# Test
cd test # TODO: Use variable for test directory name
if [ -z "$1" ]; then
    ctest # Run all tests
else
    ctest -R "$1" # Filter tests by keyword
fi

# Return to start dir
cd ../..