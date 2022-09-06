#! /bin/sh

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
  rm -rf build
elif [[ "$OSTYPE" == "darwin"* ]]; then
  cmake --build build --target clean
fi
cmake -S . -B build/
cd build && make && ./flappy_bird
