# C and C++ Projects

Systems, concurrency, data structures, and Linux networking exercises.

## Projects

- `network_monitor.c` — C Linux network diagnostics
- `network_monitor.cpp` — C++17 Linux network diagnostics
- `projects/network_health.c` — network latency/loss health classification
- `projects/ring-buffer.cpp` — fixed-capacity generic ring buffer
- `projects/threaded-reduce.cpp` — parallel reduction without shared-write races

## Build

```bash
gcc -std=c11 -O2 -Wall network_monitor.c -o network_monitor_c
gcc -std=c11 -O2 -Wall projects/network_health.c -o network_health
g++ -std=c++17 -O2 -Wall network_monitor.cpp -o network_monitor_cpp
g++ -std=c++17 -O2 -Wall projects/ring-buffer.cpp -o ring-buffer
g++ -std=c++17 -O2 -Wall -pthread projects/threaded-reduce.cpp -o threaded-reduce
```

The network monitors are read-only and use standard Linux diagnostics commands.
