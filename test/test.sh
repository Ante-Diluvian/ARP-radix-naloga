#!/bin/bash
set -e

echo "Running tests..."
./radix ./test/primer_vhoda.txt > out.txt

if grep -q "EXPECTED_RESULT" out.txt; then
    echo "Test passed."
else
    echo "Test failed!" >&2
    exit 1
fi
