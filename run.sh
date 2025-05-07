#!/usr/bin/bash

cmake . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
if [ $? -eq 0 ]; then
    echo "CMake Successful"
    echo
else
    echo "CMake Unsuccessful"
    echo
    exit "$?"
fi

cmake --build build -j 8
if [ $? -eq 0 ]; then
    echo "Make Successful"
    echo
else
    echo "Make Unsuccessful"
    echo
    exit "$?"
fi

test_file="/build/examples/testing/testing"
echo "Running test file located in $test_file"
echo
"./$test_file"
