# Memory Pool Allocator

A fixed-size memory pool allocator written in C++,
designed to be significantly faster than standard malloc
for scenarios with many allocations of the same size.

## How it works

A memory pool pre-allocates a large block of memory upfront
and manages allocations internally using a freelist - a linked chain of available slots.
This avoids repeated calls to the OS that make malloc slow.

Allocating memory is reduced to following a single pointer. Making it extremely fast and predictable.

## Benchmark

Tested on Apple M3 - 1 million allocations of 4 bytes:
| Method     | Time  |
|------------|-------|
| `malloc`   | 36 ms |
| Memory Pool | 4 ms |
**9x faster than malloc.**

## Build and run

```bash
cmake -B build
cmake --build build
```
### Run the benchmark:
`./build/benchmark`

### Run the test program:
`./build/memory_pool`

## What I learned 
- How dynamic memory allocation works under the hood
- Memory alignment on 64-bit systems
- Why game engines and databases avoid malloc in performance-critical code
