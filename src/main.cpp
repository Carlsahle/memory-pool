#include "memory_pool.h"
#include <cstddef>

int main() {
    MemoryPool pool(1024, 100);
    return 0;

    void* ptr = pool.alloc();

    pool.free(ptr);
}