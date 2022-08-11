#! /bin/bash

pushd build
cmake ..
make -j
popd