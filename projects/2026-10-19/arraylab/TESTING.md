# ArrayLab Testing Notes

The shell test harness creates a temporary build directory, compiles each example separately with C11 and strict warnings, checks a representative output for each program, and deletes generated binaries on exit.

```sh
make test
```

The smoke tests are intentionally deterministic. They validate the example code paths but do not replace sanitizer runs, fuzzing, or tests over randomized input. Useful extensions include address/undefined-behavior sanitizers and separate tests for empty input, duplicate values, and integer overflow boundaries.
