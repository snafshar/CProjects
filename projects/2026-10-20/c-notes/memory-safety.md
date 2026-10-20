# C Memory Safety Checklist

- Check allocation results before dereferencing.
- Track buffer capacity separately from current length.
- Reserve space for the terminating null byte.
- Validate indexes before access.
- Free each owned allocation exactly once.
- Define ownership rules for returned pointers.
- Avoid returning pointers to expired local storage.
- Check arithmetic before computing allocation sizes.
- Validate bounded-formatting return values.

Run tests with compiler warnings and sanitizers when available. A successful build does not prove memory safety.