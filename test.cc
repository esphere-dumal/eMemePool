#include <iostream>

int main() {
    int* ptr = (int*)(malloc(sizeof(int)));
    std::cout << "ptr value is: "<< ptr << std::endl;
    return 0;
}