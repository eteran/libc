#!/bin/bash

export CC="${CC:-gcc}"
export CFLAGS="${CFLAGS:--march=x86-64 -O3}"

echo $CFLAGS

${CC} -m64 -dM -E -x c ${CFLAGS} - <<<'' | sort | uniq

