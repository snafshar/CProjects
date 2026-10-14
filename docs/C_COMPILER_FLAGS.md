# C compiler flags

For local development, a useful warning-oriented build is:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic -O2 source.c -o app
```

- `-std=c11` selects the language standard.
- `-Wall -Wextra` enable common diagnostics.
- `-Wpedantic` highlights non-standard extensions.
- `-O2` enables optimisation for performance checks.

Use a separate debug build with sanitizers where the compiler supports them. Record the exact flags used for benchmark results.