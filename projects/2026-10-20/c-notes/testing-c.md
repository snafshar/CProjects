# Lightweight C Testing Patterns

A test executable can use assertions or explicit checks that print a useful failure message and return non-zero.

Cover empty and one-element inputs, supported minimum/maximum values, allocation and I/O failure paths, repeated calls, and unusual but valid characters. Tests should be deterministic and must not depend on a developer's personal filesystem paths.