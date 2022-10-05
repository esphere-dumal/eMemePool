#ifndef CHUNK_HH
#define CHUNK_HH

#include <cstdlib>
#include <vector>

const size_t kDefaultMxObjs = 4;

class Chunk {
public:
    Chunk(size_t start, size_t base, size_t mxobjs=kDefaultMxObjs): 
        _start(start), _base(base), _objSize(0), 
        _next(nullptr), _objUsed(std::vector<bool>(mxobjs, false)) {}

    inline bool isFull() {
        return (_objSize == _objUsed.size());
    }

    // 分配一个 obj 出去
    size_t allocObj() {
        for (auto i=0; i<_objSize; i++) {
            if (_objUsed[i] == false) {
                _objUsed[i] = true;
                ++_objSize;
                return offsetToAddr(i);
            }
        }
        return -1;
    }

    // 回收一个 obj
    void freeObj(size_t addr) {
        _objUsed[addrToOffset(addr)] = false;
        --_objSize;
    }

private:
    size_t  _start;
    size_t  _base;
    size_t  _objSize;
    Chunk*  _next;
    std::vector<bool> _objUsed;

    inline size_t offsetToAddr(size_t offset) {
        return _start + _base * offset;
    }

    inline size_t addrToOffset(size_t addr) {
        return (addr - _start) / _base;
    }
};


#endif  CHUNK_HH