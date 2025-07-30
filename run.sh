#!/bin/bash
TARGET=$1
cmake -DTARGET=${TARGET} -B build && cmake --build build --target run
