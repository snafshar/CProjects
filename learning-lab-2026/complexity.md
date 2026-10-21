# Complexity reference

| Operation | Typical complexity |
|---|---:|
| Vector indexed access | O(1) |
| Vector search | O(n) |
| Binary search on sorted vector | O(log n) |
| Set lookup/insertion | O(log n) for `std::set` |
| Vector-backed stack push | amortized O(1) |

Always state assumptions, such as sorted input for binary search.