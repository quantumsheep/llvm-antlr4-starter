#!/bin/bash

set -xe

docker build . -t llvm-antlr4-starter-dev

docker run --rm -it \
    --mount type=bind,source="$(pwd)"/,target=/usr/src/app/ \
    llvm-antlr4-starter-dev
