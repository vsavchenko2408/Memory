#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <cstdint>

template<typename T>
class Shared_ptr
{
    T* _data;
    size_t* _count;
    public:
    Shared_ptr(T* data = nullptr) : _data(data), _count(new size_t(1))
    {}
    Shared_ptr(T data) : _data(new T(data)), _count(new size_t(1))
    {}
    Shared_ptr(const Shared_ptr& copy): _data(copy._data), _count(copy._count)
    {
        ++(*_count);
    }
    Shared_ptr& operator=(const Shared_ptr& copy)
    {
        if(this != &copy)
        {
        --(*_count);
            if(*_count == 0)
            {
                delete _data;
                delete _count;
            }
            _data = copy._data;
            _count = copy._count;
            ++(*_count);
        }
        return *this;
    }



    T& operator*() 
    {
        return *_data;
    }
    T& operator*() const
    {
        return *_data;
    }
    ~Shared_ptr()
    {
        --(*_count);
        if(*_count == 0)
        {
            delete _data;
            delete _count;
        }
    }

};

#endif