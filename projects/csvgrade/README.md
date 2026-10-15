# CSVGrade — Student Score Analyzer in C

CSVGrade reads a simple comma-separated file of student names and numeric scores, then reports the average, highest score, and lowest score. It is designed to practise C file I/O, parsing, validation, and memory safety.

## Build and run

    gcc -std=c11 -Wall -Wextra -Wpedantic -O2 csvgrade.c -o csvgrade
    ./csvgrade sample.csv

Input format: one record per line, with a name followed by a score, for example `Ada Lovelace,95.5`. Names should not contain commas in this starter version.

## Learning goals

- Open and read files safely
- Parse and validate numbers with strtod
- Use structs to represent records
- Handle malformed rows without crashing
- Keep a running summary without storing every row

## Extensions

1. Support quoted CSV fields.
2. Add a pass threshold option.
3. Print a sorted ranking.
4. Add tests for empty files and malformed scores.
