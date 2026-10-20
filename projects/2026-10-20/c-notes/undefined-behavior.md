# Common C Undefined Behavior Pitfalls

Watch for:
- Signed integer overflow.
- Out-of-bounds array access.
- Use-after-free and double-free.
- Reading uninitialized automatic variables.
- Dereferencing invalid or misaligned pointers.
- Data races between unsynchronized threads.
- Incorrect format specifiers in variadic functions.

Undefined behavior means the language standard does not define the result. It may appear to work during one run and fail after compiler or optimization changes.
