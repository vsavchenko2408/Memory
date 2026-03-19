#ifndef UNIQ_PTR_H
#define UNIQ_PTR_H

template<typename T>
class Uniq_ptr
{
    T* _data;
    public:
    Uniq_ptr() : _data(nullptr)
    {}
    Uniq_ptr(T obj) : _data(new T(obj))
    {}

    T& operator*()
    {
        return *_data;
    }
    ~Uniq_ptr()
    {
        delete _data;
    }
};

#endif