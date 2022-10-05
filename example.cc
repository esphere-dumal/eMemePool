#include <iostream>
#include <cstdlib>

const size_t KB = 1024;
const size_t MB = KB * KB;

int main() {
    void* ptr = malloc(MB * 1024);
    uint32_t addr = size_t(ptr);
    std::cout << addr << " ";

    std::cin >> addr;
    free(ptr);
    return 0;
}
