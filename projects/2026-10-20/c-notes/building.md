# Reproducible C Builds

Development baseline:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g source.c -o program
```

For supported compilers, try a separate diagnostic build:

```sh
cc -std=c11 -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer source.c -o program-debug
```

Flags vary by compiler and OS. Treat warnings as findings to understand rather than text to suppress. Keep optimized performance builds separate from diagnostic builds.