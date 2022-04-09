#!/bin/bash
FLAGS="-x c -march=native -O3 -mno-mmx -mno-sse -mno-sse2"
clang -m64 -dM -E $FLAGS - <<<'' | sort | uniq

