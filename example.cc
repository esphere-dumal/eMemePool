#include <iostream>
#include <cstdlib>
#include "src/memorypool.hh" 

using ll = long long;

int main() {
    auto mp = new MemoryPool(MB);

    int* ptr1 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr2 = (int*)(mp->eMalloc(sizeof(int)));
    mp->eFree((void*)(ptr2));
    int* ptr3 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr4 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr5 = (int*)(mp->eMalloc(sizeof(int)));
    int* ptr12 = (int*)(mp->eMalloc(sizeof(int)));

    ll* ptr6 = (ll*)(mp->eMalloc(sizeof(ll)));
    ll* ptr7 = (ll*)(mp->eMalloc(sizeof(ll)));
    ll* ptr8 = (ll*)(mp->eMalloc(sizeof(ll)));
    ll* ptr9 = (ll*)(mp->eMalloc(sizeof(ll)));
    ll* ptr10 = (ll*)(mp->eMalloc(sizeof(ll)));
    ll* ptr11 = (ll*)(mp->eMalloc(sizeof(ll)));


    std::cout << ptr1 << std::endl;
    std::cout << ptr3 << std::endl;
    std::cout << ptr4 << std::endl;
    std::cout << ptr5 << std::endl;
    std::cout << ptr12 << std::endl;
    std::cout << ptr6 << std::endl;
    std::cout << ptr7 << std::endl;
    std::cout << ptr8 << std::endl;
    std::cout << ptr9 << std::endl;
    std::cout << ptr10 << std::endl;
    std::cout << ptr11 << std::endl;
    return 0;
}

