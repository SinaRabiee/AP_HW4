template <typename T>
UniquePtr<T>::UniquePtr(T* arr)
{
    _p = arr;
}

template <typename T, typename... U>
T* make_unique(U&&... args)
{
    return new T(std::forward<U>(args)...);
}

template <typename T>
UniquePtr<T>::UniquePtr()
{
    _p = nullptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    if (_p) {
        delete _p;
        _p = nullptr;
    }
}

template <typename T>
T* UniquePtr<T>::get()
{
    return _p;
}

template <typename T>
T& UniquePtr<T>::operator*()
{
    return *_p;
}

template <typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}

template <typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T* arr)
{
    delete _p;
    _p = arr;
}

template <typename T>
T* UniquePtr<T>::release()
{
    T* Ptr { _p };
    _p = nullptr;
    return Ptr;
}
