#include <iostream>
#include "../include/uniq_ptr.h"
#include "../include/shared_ptr.h"

int main()
{

    Uniq_ptr<float> fptr(15.2);
    std::cout << "fptr: " << *fptr.get() << std::endl;
}