# Memory-safety checklist

- Prefer `std::vector`, `std::string`, and RAII-managed resources.
- Avoid raw owning pointers when a standard smart pointer is appropriate.
- Check container bounds where inputs are untrusted.
- Compile development builds with `-Wall -Wextra -Wpedantic`.
- Where available, run tests with AddressSanitizer and UndefinedBehaviorSanitizer.