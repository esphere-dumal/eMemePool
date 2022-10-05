#include "memorypool.hh"

MemoryPool::MemoryPool(size_t maxsize): _mxsize(maxsize), _startChunk(nullptr) {
    void* ptr = malloc(_mxsize);
    std::cout << ptr << std::endl;
    if (ptr == nullptr) {
        std::cerr << "[eMemoryPool]: can't get enough memory to init memorypool" << std::endl;
    }
    _startAddress = size_t(ptr);
    _betweenPoint = _startAddress;
    _startChunk   = new Chunk(_startAddress, 0); // 作为哨兵
}   

void* MemoryPool::eMalloc(size_t size) {
    Chunk *ck=_startChunk, *last;
    while(ck!=nullptr) {
        // if able to find a proper chunk
        if (ck->_base == size && ck->isFull()==false) {
            return (void*)(ck->allocObj());
        }
        last = ck;
        ck = ck->_next;
    }

    // try to create a new chunk
    // todo: recycle before creating
    size_t needMemory = size*kDefaultMxObjs;
    if (ableToCreate(needMemory)) {
        last->_next = new Chunk(_betweenPoint, size);
        _betweenPoint = _betweenPoint + needMemory+1;
        return (void*)(last->_next->allocObj());
    }


    return nullptr;
}