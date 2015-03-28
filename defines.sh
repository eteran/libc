#!/bin/sh
FLAGS="-x c -march=native -std=c11 -pedantic -Wextra -Wall -ffreestanding -O2 -g3 -Wno-long-long"
gcc-4.9.2 -m64 -dM -E $FLAGS - <<<'' | sort | uniq

