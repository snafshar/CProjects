# Reproducible C Builds

A useful development baseline is:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -g source.c -o program
```

For supported compilers, try AddressSanitizer and UndefinedBehaviorSanitizer in a separate debug build:

```sh
cc -std=c11 -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer source.c -o program-debug
```

Flags vary by compiler and operating system. Treat warnings as findings to understand, not just text to suppress. Keep optimized performance builds separate from diagnostic builds.
