#include <iostream>
#include "../include/memory.h"

int main()
{
    Weak_ptr<int> ptr(15);
    std::cout << "Data: " << *ptr << std::endl;
    std::cout << "Adress ptr: " << &ptr << std::endl;
    std::cout << "Data: " << ptr.get() << std::endl;
}