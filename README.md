# C and C++ Projects

Networking and systems-programming exercises.

## Projects

- `threaded-reduce.cpp` — parallel reduction
- `ring-buffer.cpp` — fixed-capacity queue
- `network_monitor.cpp` — read-only Linux network diagnostics monitor

## Build

`g++ -std=c++17 -O2 -Wall network_monitor.cpp -o network_monitor`

## Run

`./network_monitor`

The monitor uses standard Linux networking tools and does not modify network configuration.
