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

    Shared_ptr(Shared_ptr&& move) noexcept : _data(move._data), _count(move._count)
    {
        move._count = nullptr;
        move._data = nullptr;
    }

    Shared_ptr& operator=(Shared_ptr&& move)
    {
        if(this != &move)
        {
            --(*_count);
            if(*_count == 0)
            {
                delete _data;
                delete _count;
            }
            _data = move._data;
            _count = move._count;
            move._data  = nullptr;
            move._count = nullptr;
        }
        return *this;
    }

    T* get() const noexcept
    {
        return _data;
    }
    T& operator*() 
    {
        return *_data;
    }
    T& operator*() const
    {
        return *_data;
    }
    T operator->()
    {
        return _data;
    }
    T operator->() const
    {
        return _data;
    }
    ~Shared_ptr()
    {
        if(_count == nullptr) return;
        --(*_count);
        if(*_count == 0)
        {
            delete _data;
            delete _count;
        }
    }

};

#endif