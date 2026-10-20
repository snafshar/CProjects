# C Command-Line Validation

Check `argc` before reading `argv[i]`. When parsing integers, use `strtol`, check the end pointer and `errno`, and validate application limits after conversion. Distinguish missing input from a valid zero. Print usage to stderr for invalid invocation and return a non-zero status.

Avoid `atoi` when malformed input and overflow must be detected; it has no reliable error-reporting interface.