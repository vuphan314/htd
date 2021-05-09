#!/bin/bash

mkdir -p build
cd build
cmake ..
make -s
make -s install
