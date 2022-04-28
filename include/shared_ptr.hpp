
template <typename T>
SharedPtr<T>::SharedPtr(T* arr)
{
    _p = arr;
    count = new int { 1 };
}

template <typename T, typename... U>
T* make_shared(U&&... args)
{
    // count = new int { 1 };
    return new T(std::forward<U>(args)...);
}

template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p = nullptr;
    count = new int { 1 };
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    --(*count);
    if (*count == 0) {
        delete count;
        count = new int {};
        delete _p;
        _p = nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& Ptr)
    : _p { Ptr._p }
    , count { Ptr.count }
{
    ++(*count);
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& Ptr)
{
    if (this == &Ptr)
        return *this;
    delete count;
    delete _p;
    _p = Ptr._p;
    count = Ptr.count;
    ++(*count);
    return *this;
}

template <typename T>
int SharedPtr<T>::use_count()
{
    return *count;
}

template <typename T>
T* SharedPtr<T>::get()
{
    return _p;
}

template <typename T>
T& SharedPtr<T>::operator*()
{
    return *_p;
}

template <typename T>
T* SharedPtr<T>::operator->()
{
    return _p;
}

template <typename T>
void SharedPtr<T>::reset()
{
    delete _p;
    delete count;
    _p = nullptr;
    count = new int {};
}

template <typename T>
void SharedPtr<T>::reset(T* arr)
{
    delete _p;
    delete count;
    _p = arr;
    count = new int { 1 };
}

template <typename T>
SharedPtr<T>::operator bool() const
{
    if (_p == nullptr)
        return false;
    else
        return true;
}