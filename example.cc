#include <iostream>
#include <cstdlib>
#include "src/memorypool.hh" 

int main() {
    auto mp = new MemoryPool(16);

    int* ptr1 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr2 = (int*)(mp->eMalloc(sizeof(int)));
    mp->eFree((void*)(ptr2));
    int* ptr3 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr4 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr5 = (int*)(mp->eMalloc(sizeof(int)));

    mp->eFree(nullptr);

    std::cout << ptr1 << std::endl;
    std::cout << ptr3 << std::endl;
    std::cout << ptr4 << std::endl;
    std::cout << ptr5 << std::endl;
    return 0;
}
