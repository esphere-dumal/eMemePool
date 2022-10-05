#include <iostream>

int main() {
    void* ptr = malloc(sizeof(int));
    void* intptr = (int*)ptr;
    std::cout << "ptr value is: "<< ptr << std::endl;
    std::cout << "intptr value is: "<< intptr << std::endl;

    std::cout << "(int)" << size_t(ptr) << std::endl;
    return 0;
}