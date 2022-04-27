#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
#include <memory>
#include <utility>

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* arr);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr& Ptr) = delete;
    UniquePtr<T>& operator=(const UniquePtr& Ptr) = delete;
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* arr);
    T* release();
    operator bool() const;

private:
    T* _p;
};

template <typename T, typename... U>
T* make_unique(U&&... args);

#include "unique_ptr.hpp"
#endif // UNIQUE_PTR