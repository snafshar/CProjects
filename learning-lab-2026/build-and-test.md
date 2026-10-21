# Build and test

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 linear_search.cpp -o linear_search
./linear_search
```

For debug builds, add `-g -O0`. If supported, use `-fsanitize=address,undefined` during tests. Keep generated executables out of version control.