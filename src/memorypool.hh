#ifndef MEMORYPOOL_HH
#define MEMORYPOOL_HH

#include <cstdlib>
#include <iostream>

const size_t KB = 1024;
const size_t MB = KB * MB;
const size_t kDefaultMaxSize = 4*KB;

class MemoryPool {
public:
    // Init memory pool with a maxsize
    MemoryPool(size_t maxsize = kDefaultMaxSize);

    // return an address, nullptr when failed to allocate
    void* eMalloc(size_t size);

    // free target address
    void* free(void* toBeFree);

private:
    /*
     *  free memory is described by 
     *  _mxsize, _startAddress, _betweenPoint
     */
    size_t  _mxsize;
    size_t  _startAddress;
    size_t  _betweenPoint;



};

#endif