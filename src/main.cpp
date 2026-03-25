#include <iostream>
#include "../include/memory.h"

int main()
{

    Shared_ptr<int> sptr(32);
    Weak_ptr<int> wptr(sptr);

}