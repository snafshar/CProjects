#!/usr/bin/env sh
set -eu
HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
BUILD=$(mktemp -d)
trap 'rm -rf "$BUILD"' EXIT HUP INT TERM
CC=${CC:-cc}
for source in array_stats linear_search binary_search insertion_sort merge_sorted_arrays remove_duplicates two_sum matrix_multiply; do
  "$CC" -std=c11 -Wall -Wextra -Wpedantic -Werror -O2 "$HERE/$source.c" -o "$BUILD/$source"
done
"$BUILD/array_stats" | grep -F 'count=5 min=1 max=9 mean=5.40'
"$BUILD/linear_search" | grep -F 'target=7 index=2'
"$BUILD/binary_search" | grep -F 'target=7 index=3'
"$BUILD/insertion_sort" | grep -F 'sorted: -3 0 2 4 9'
"$BUILD/merge_sorted_arrays" | grep -F 'merged: 1 2 3 4 6 8'
"$BUILD/remove_duplicates" | grep -F 'unique: 1 2 3 5'
"$BUILD/two_sum" | grep -F 'target=9 indices=0,1 values=2,7'
"$BUILD/matrix_multiply" | grep -F '19 22'
"$BUILD/matrix_multiply" | grep -F '43 50'
echo "ArrayLab smoke tests passed."
