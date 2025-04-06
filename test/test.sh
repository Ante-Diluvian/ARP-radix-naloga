#!/bin/bash
set -e

echo "Running tests..."

./radix ./test/primer_vhoda.txt
mv out.txt ./test/out.txt

if diff -q ./test/out.txt ./test/primer_izhoda.txt > /dev/null; then
    echo "Test passed."
else
    echo "Test failed! Output differs from expected." >&2
    echo "Differences:"
    diff ./test/out.txt ./test/primer_izhoda.txt || true
    exit 1
fi
