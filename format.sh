#!/bin/bash

cd $(dirname $0)
find src include tests -name "*.[ch]" | xargs clang-format -i
