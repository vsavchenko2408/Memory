#ifndef UNIQ_PTR_H
#define UNIQ_PTR_H
#include <utility>
template<typename T>
class Uniq_ptr
{
    T* _data;
    public:
    Uniq_ptr(T obj) : _data(new T(obj)) 
    {}
    Uniq_ptr(T* ptr = nullptr) noexcept : _data(ptr)
    {}

    Uniq_ptr(const Uniq_ptr&) = delete;
    Uniq_ptr operator=(const Uniq_ptr&) = delete;

    Uniq_ptr(Uniq_ptr&& move) noexcept : _data(move._data)
    {
        move._data = nullptr;
    }
    Uniq_ptr& operator=(Uniq_ptr&& move) noexcept
    {
        if(this != &move)
        {
            delete _data;
            _data = move._data;
            move._data = nullptr;
        }
        return *this;
    }
    T& operator*()
    {
        return *_data;
    }
    const T& operator*() const
    {
        return *_data;
    }
    T* operator->()
    {
        return _data;
    }
    const T* operator->() const
    {
        return _data;
    }
    T* get() const noexcept
    {
        return _data;
    }
    ~Uniq_ptr()
    {
        delete _data;
    }
};

#endif