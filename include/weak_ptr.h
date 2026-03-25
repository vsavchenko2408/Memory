#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include "shared_ptr.h"
template<typename T>
class Weak_ptr
{
    T* _data;
    unsigned int* _shared;
    unsigned int* _weak; 
    public:
    Weak_ptr(): _data(nullptr), _shared(nullptr), _weak(nullptr)
    {}
    Weak_ptr(const Shared_ptr<T>& sp) : _data(sp._data), _shared(sp._shared), _weak(sp._weak)
    {
    ++(*_weak);
    }

    Shared_ptr<T> lock() const
    {
    if(*_shared == 0) return Shared_ptr<T>(nullptr);
    ++(*_shared);
    return Shared_ptr<T>(_data, _shared, _weak); 
    }   
    
    bool expired() const
    { 
        return *_shared == 0;
    }
    T& operator*()
    {
        return *_data;
    }
    T& operator*() const
    {
        return *_data;
    }
    T* operator->()
    {
        return _data;
    }
    T* operator->() const
    {
        return _data;
    }
    T* get()
    {
        return _data;
    }
    ~Weak_ptr()
    {
        if(_weak == nullptr) return;
        --(*_weak);
        if(*_weak == 0 && *_shared == 0)
        {
            delete _shared;
            delete _weak;
        }
    }
};
#endif