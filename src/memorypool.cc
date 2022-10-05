#include "memorypool.hh"

MemoryPool::MemoryPool(size_t maxsize): _mxsize(maxsize), _startChunk(nullptr) {
    void* ptr = malloc(_mxsize);
    if (ptr == nullptr) {
        std::cerr << "[eMemoryPool]: can't get enough memory to init memorypool" << std::endl;
    }
    _startAddress = size_t(ptr);
    _betweenPoint = _startAddress;
}   
