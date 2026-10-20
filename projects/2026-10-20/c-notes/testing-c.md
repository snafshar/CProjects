# Lightweight C Testing Patterns

A simple C test executable can use assertions or explicit checks that print a useful failure message and return non-zero.

Cover:
- Empty and one-element inputs.
- Minimum and maximum supported values.
- Invalid pointers where the API contract permits checking them.
- Allocation and I/O failure paths where they can be simulated.
- Repeated calls to reveal leaked state.
- Inputs with spaces or unusual but valid characters.

Tests should be deterministic and should never depend on a developer's personal filesystem paths.
