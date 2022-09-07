#! /bin/sh

cmake -S . -B build/
cd build && make
./flappy_bird
