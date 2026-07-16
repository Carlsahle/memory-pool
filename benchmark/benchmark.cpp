#include "memory_pool.h"
#include <cstddef>
#include <chrono>
#include <iostream>

int main() {
    int** pointers = new int*[1000000];
    MemoryPool pool(sizeof(int), 1000000);

    auto mallocstart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        pointers[i] = (int*)malloc(sizeof(int));
    }
    for (int i = 0; i < 1000000; i++) {
        free(pointers[i]);
    }
    auto mallocend = std::chrono::high_resolution_clock::now();
    auto mallocduration = std::chrono::duration_cast<std::chrono::milliseconds>(mallocend - mallocstart).count();

    auto poolstart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        pointers[i] = (int*) pool.alloc();
    }
    for (int i = 0; i < 1000000; i++) {
        pool.free(pointers[i]);
    }
    auto poolend = std::chrono::high_resolution_clock::now();
    auto poolduration = std::chrono::duration_cast<std::chrono::milliseconds>(poolend - poolstart).count();

    std::cout << "Malloc duration: " << mallocduration << " ms" << std::endl;
    std::cout << "Pool duration: " << poolduration << " ms" << std::endl;

    delete[] pointers; // free the allocated array of pointers

    return 0;
}