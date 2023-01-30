#!/bin/bash
FLAGS="-x c -march=native -O3"
clang -m64 -dM -E $FLAGS - <<<'' | sort | uniq

