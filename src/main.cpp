#include <iostream>
#include "../include/uniq_ptr.h"

int main()
{
    Uniq_ptr<int> ptr(15);
    Uniq_ptr<int> ptr1 = ptr;
    std::cout << *ptr << std::endl;
}