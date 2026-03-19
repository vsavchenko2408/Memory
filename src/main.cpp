#include <iostream>
#include "../include/uniq_ptr.h"

int main()
{
    Uniq_ptr<int> ptr(15);
    std::cout << *ptr << std::endl;
}