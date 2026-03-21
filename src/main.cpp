#include <iostream>
#include "../include/uniq_ptr.h"
#include "../include/shared_ptr.h"

int main()
{
    Shared_ptr<int> ptr(new int(15));
    Shared_ptr<float> fptr(15.2);
    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "fptr: " << *fptr << std::endl;
}