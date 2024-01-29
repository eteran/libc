#!/bin/bash
FLAGS="-x c -march=native -O3"
gcc -m64 -dM -E $FLAGS - <<<'' | sort | uniq

