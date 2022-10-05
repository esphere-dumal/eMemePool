#include <iostream>
#include <cstdlib>
#include "src/memorypool.hh" 

int main() {
    auto mp = new MemoryPool(MB);

    int* ptr1 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr2 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr3 = (int*)(mp->eMalloc(sizeof(int)));

    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr3 << std::endl;

    return 0;
}
