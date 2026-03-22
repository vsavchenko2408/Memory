#ifndef WEAK_PTR_H
#define WEAK_PTR_H

template<typename T>
class Weak_ptr
{
    T* _data;
    unsigned int* _shared;
    unsigned int* _weak; 
    public:
    Weak_ptr(): _data(nullptr), _shared(0), _weak(0)
    {}
    Weak_ptr(T obj): _data(new T(obj)), _shared(new unsigned int(0)), _weak(new unsigned int(1))
    {}

    T operator*()
    {
        return *_data;
    }
    T operator*() const
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
        if(_shared == 0 && _weak == 0)
        {
            delete _data;
            delete _weak;
            delete _shared;
        }
    }
};
#endif