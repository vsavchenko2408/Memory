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
    Uniq_ptr(T& copy)
    {
        if(copy._data != nullptr)
        {
            _data = copy._data;
            delete copy._data;
        }
        else
        {
            _data(nullptr);
        }
    }
    Uniq_ptr& operator=(Uniq_ptr& copy)
    {
        if(this != &copy)
        {
            delete _data;
            _data = copy._data;
            delete copy._data;
        }
        else
        {
            delete _data;
            _data(nullptr);
        }
        return *this;
    }
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