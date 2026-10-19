# C and C++ Projects

Systems, concurrency, data structures, and Linux networking exercises.

## Projects

- `network_monitor.c` — C Linux network diagnostics
- `network_monitor.cpp` — C++17 Linux network diagnostics
- `projects/network_health.c` — network latency/loss health classification
- `projects/ring-buffer.cpp` — fixed-capacity generic ring buffer
- `projects/threaded-reduce.cpp` — parallel reduction without shared-write races
- [CSVGrade](https://github.com/snafshar/CProjects/tree/main/projects/csvgrade) — validates score rows and reports summary statistics
- [ArrayLab](https://github.com/snafshar/CProjects/tree/main/projects/2026-10-19/arraylab) — standalone C11 array algorithms with strict-warning smoke tests

## Build

```bash
gcc -std=c11 -O2 -Wall network_monitor.c -o network_monitor_c
gcc -std=c11 -O2 -Wall projects/network_health.c -o network_health
g++ -std=c++17 -O2 -Wall network_monitor.cpp -o network_monitor_cpp
g++ -std=c++17 -O2 -Wall projects/ring-buffer.cpp -o ring-buffer
g++ -std=c++17 -O2 -Wall -pthread projects/threaded-reduce.cpp -o threaded-reduce
sh projects/csvgrade/test_csvgrade.sh
sh projects/2026-10-19/arraylab/test_arraylab.sh
```

The network monitors are read-only and use standard Linux diagnostics commands. The C examples include standalone tests to make behavior easier to reproduce.
