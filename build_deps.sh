#!/bin/bash

mkdir deps
cd deps

# Build and install vitaGL, mathneon and vitaShaRK

git clone https://github.com/Rinnegatamante/vitaGL.git
cd vitaGL
git reset --hard 9c963ab
make HAVE_SBRK=1 HAVE_SHARK=1 install -j4

cd ../../
rm -rf deps
