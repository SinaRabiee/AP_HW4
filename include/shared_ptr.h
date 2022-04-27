#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
#include <utility>

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* arr);
    SharedPtr();
    ~SharedPtr();
    SharedPtr(const SharedPtr& Ptr);
    SharedPtr<T>& operator=(const SharedPtr& Ptr);
    size_t use_count();
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* arr);
    T* release();
    operator bool() const;

private:
    T* _p;
    int* count;
};

template <typename T, typename... U>
T* make_shared(U&&... args);

#include "shared_ptr.hpp"
#endif // SHARED_PTR