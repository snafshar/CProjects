# C Memory Safety Checklist

- Check allocation results before dereferencing.
- Keep track of buffer capacity separately from current length.
- Reserve space for the terminating null byte in strings.
- Validate indexes before access.
- Free each owned allocation exactly once.
- Set ownership rules for returned pointers.
- Avoid returning pointers to expired local storage.
- Check arithmetic before computing allocation sizes.
- Prefer bounded formatting functions and still validate their return values.

Run tests with compiler warnings and sanitizers when available. A successful build does not prove memory safety.
