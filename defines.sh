#!/bin/sh
FLAGS="-x c -march=native -std=c11 -pedantic -Wextra -Wall -ffreestanding -O2 -g3 -Wno-long-long"
gcc -m64 -dM -E $FLAGS - <<<'' | sort | uniq

