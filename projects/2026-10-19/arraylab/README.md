# ArrayLab — Small C Algorithms

ArrayLab is a collection of small, independent C11 programs for practicing array traversal, searching, sorting, duplicate removal, pair sums, and matrix multiplication.

## Build and test

```sh
make test
# or
sh test_arraylab.sh
```

Each source file contains its own `main` so that the examples can be compiled independently. The programs use fixed demonstration data to keep the algorithm visible and repeatable.

## Programs

- `array_stats.c`: count, minimum, maximum, and arithmetic mean.
- `linear_search.c` and `binary_search.c`: compare search strategies.
- `insertion_sort.c`: in-place insertion sort on a small array.
- `merge_sorted_arrays.c`: merge two sorted arrays.
- `remove_duplicates.c`: compact duplicates in an already-sorted array.
- `two_sum.c`: find a pair of values that matches a target.
- `matrix_multiply.c`: multiply two small 2×2 matrices.

The project aims for portability and readable control flow, not maximum performance.
