#! /bin/sh

cmake --build build --target clean
cmake -S . -B build/
cd build && make && ./flappy_bird
