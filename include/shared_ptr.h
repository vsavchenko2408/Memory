#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <cstdint>
template<typename T> class Weak_ptr;

template<typename T>
class Shared_ptr
{
    T* _data;
    unsigned int* _shared;
    unsigned int* _weak;
    Shared_ptr(T* data, unsigned int* shared, unsigned int* weak) : _data(data), _shared(shared), _weak(weak)
    {}
    public:
        template<typename U>
        friend class Weak_ptr;
    Shared_ptr(T* data = nullptr) : _data(data), _shared(new unsigned int(1)), _weak(new unsigned int(0))
    {}
    Shared_ptr(T data) : _data(new T(data)), _shared(new unsigned int(1)), _weak(new unsigned int(0))
    {}
    Shared_ptr(const Shared_ptr& copy): _data(copy._data), _shared(copy._shared), _weak(copy._weak)
    {
        ++(*_shared);
    }
    Shared_ptr& operator=(const Shared_ptr& copy)
    {
        if(this != &copy)
        {
        --(*_shared);
            if(*_shared == 0)
            {
                delete _data;
                delete _shared;
                delete _weak;
            }
            _data = copy._data;
            _shared = copy._shared;
            _weak = copy._weak;
            ++(*_shared);
        }
        return *this;
    }

    Shared_ptr(Shared_ptr&& move) noexcept : _data(move._data), _shared(move._shared), _weak(move._weak)
    {
        move._shared = nullptr;
        move._data = nullptr;
        move._weak = nullptr;
    }

    Shared_ptr& operator=(Shared_ptr&& move)
    {
        if(this != &move)
        {
            --(*_shared);
            if(*_shared == 0)
            {
                delete _data;
                delete _shared;
                delete _weak;
            }
            _data = move._data;
            _shared = move._shared;
            _weak = move._weak;
            move._data  = nullptr;
            move._shared = nullptr;
            move._weak = nullptr;
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
    T* operator->()
    {
        return _data;
    }
    T* operator->() const
    {
        return _data;
    }
    ~Shared_ptr()
    {
    if(_shared == nullptr) return;
    --(*_shared);
    if(*_shared == 0)
    {
        delete _data;
        _data = nullptr;
        if(*_weak == 0)
        {
            delete _shared;
            delete _weak;
        }
    }
    }

    
};

#endif