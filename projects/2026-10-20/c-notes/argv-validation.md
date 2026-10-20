# C Command-Line Validation

- Check `argc` before reading `argv[i]`.
- Check conversion end pointers when using `strtol`.
- Inspect `errno` for range errors.
- Validate application-specific limits after conversion.
- Distinguish missing input from a valid zero.
- Print usage to stderr for invalid invocation.
- Return a non-zero status for invalid arguments.

Avoid `atoi` when malformed input and overflow must be detected; it does not provide a reliable error-reporting interface.
