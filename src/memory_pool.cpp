#include "memory_pool.h"
#include <cstddef>

MemoryPool::MemoryPool(std::size_t objectSize, std::size_t capacity) 
    : objectSize(objectSize), capacity(capacity), freeList(nullptr) {

    if (objectSize < sizeof(void*)) {
    objectSize = sizeof(void*);
    }    
    // Steg 1: allokera ett stort minnesblock
    memory = ::operator new(objectSize * capacity);

    // Steg 2: Bygg free list
    for (std::size_t i = 0; i < capacity - 1; i++) {
        void* current = (char*)memory + i * objectSize;
        void* next    = (char*)memory + (i + 1) * objectSize;
        *((void**)current) = next;
    }

    // Sista sloten pekar på nullptr
    void* last = (char*)memory + (capacity - 1) * objectSize;
    *((void**)last) = nullptr;
    
    // freeList pekar på första sloten
    freeList = memory;
}

void* MemoryPool::alloc() {
    void* current = freeList;
    freeList = *((void**)freeList);

    return current;
}

void MemoryPool::free(void* ptr) {
    *((void**)ptr) = freeList;
    freeList = ptr;
    return;
}

// Destruktor
MemoryPool::~MemoryPool() {
    operator delete(memory);
}