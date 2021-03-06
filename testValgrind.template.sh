#!/bin/bash

set -e

for i in ${CMAKE_CURRENT_BINARY_DIR}/*Test; do
    valgrind --error-exitcode=1 --leak-check=full $i
done

for i in ${CMAKE_CURRENT_BINARY_DIR}/wasm-module/*Test; do
    valgrind --error-exitcode=1 --leak-check=full $i
done

for i in ${CMAKE_CURRENT_SOURCE_DIR}/libwasmint/tests/wast_tests/*.wast; do
    valgrind --error-exitcode=1 --leak-check=full ./wasmint_wast $i
done
