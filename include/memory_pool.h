// alignas is when a variable is forced to a larger boundary of alignment
// alignas is used to self manipulate the alignment of a variable

// alignof is a operator that returns the alignment boundary of a variable

#pragma once
#include <cstddef>

class MemoryPool {
    public:
    MemoryPool(std::size_t objectSize, std::size_t capacity);
    ~MemoryPool();

    void* alloc();
    void free(void* ptr);

private:
    void*       memory;
    void*       freeList;
    std::size_t objectSize;
    std::size_t capacity;
};