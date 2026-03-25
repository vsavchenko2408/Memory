#include <iostream>
#include "../include/memory.h"

int main()
{

    Shared_ptr<int> sptr(32);
    Weak_ptr<int> wptr(sptr);
 
std::cout << wptr.expired() << std::endl; 


auto lck = wptr.lock();
if(lck.get() == nullptr)
    std::cout << "Object destroyed" << std::endl;


struct Node {
    int value;
    Shared_ptr<Node> next;
    Weak_ptr<Node> prev; 
};
}