#!/usr/bin/bash

cmake . -B build -DCMAKE_BUILD_TYPE=Debug
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

./build/diligent_triangle
