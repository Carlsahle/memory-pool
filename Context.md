# Session 1
## Done 
- MemoryPool.h, class declaration
- MemoryPool.cpp, constructor, alloc(), free(), destructor
## Next session
- Main.cpp
## Notes
MemoryPool::MemoryPool() means "this belongs to the class MemoryPool"
::operator delete(memory) frees the memory
# Session 2
## Done
- CMakeLists.txt, this run the program
- main.cpp, create the memory pool, allocate memory, free memory
## Next session
- benchmark.cpp
# Session 3
## Done
- benchmark.cpp , used chrono as a timer to compare malloc with my pool
- changed in CMakeLists.txt and changed two lines in memory_pool.cpp
## Notes
- MVP completed
- Project shows that my Memory Pool allocator is 9x faster than malloc