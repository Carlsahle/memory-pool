cmake_minimum_required(VERSION 3.15)
project(MemoryPool)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory_pool
    src/main.cpp
    src/memory_pool.cpp
)

target_include_directories(memory_pool PRIVATE include)

add_executable(benchmark
    benchmark/benchmark.cpp
    src/memory_pool.cpp
)

target_include_directories(benchmark PRIVATE include)