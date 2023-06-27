#include "../include/Vector.hpp"
#include <memory>
#include <climits>

template <typename T>
Vector<T>::Vector(): sz(0), cap(1) {
    arr = reinterpret_cast<T*>(new int8_t[sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(size_t count): sz(0), cap(count)  {
    arr = reinterpret_cast<T*>(new int8_t[count * sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst): sz(lst.size()), cap(sz), arr(new T[sz]) {
    std::copy(lst.begin(), lst.end(), arr);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vec): Vector(vec.cap) {
    memcpy(arr, vec.arr, vec.sz * sizeof(T));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
    if (this == &vec) {
        return *this;
    }

    this->resize(vec.sz);
    for (int i = 0; i < vec.sz; ++i) {
        this->arr[i] = vec.arr[i];
    }

    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < sz; ++i){
        arr[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(arr);
}

template <typename T>
T& Vector<T>::operator[](size_t i) {
    return arr[i];
}

template <typename T>
T& Vector<T>::at(size_t i) {
    if (i >= sz) {
        throw std::out_of_range("Index out of range!");
    }
    return arr[i];
}

template <typename T> 
T& Vector<T>::front() {
    return arr[0];
}

template <typename T> 
T& Vector<T>::back() {
    return arr[sz - 1];
}

template <typename T>
const T& Vector<T>::operator[](size_t i) const {
    return arr[i];
}

template <typename T>
const T& Vector<T>::at(size_t i) const {
    if (i >= sz) {
        throw std::out_of_range("Index out of range!");
    }
    return arr[i];
}

template <typename T> 
const T& Vector<T>::front() const {
    return arr[0];
}

template <typename T> 
const T& Vector<T>::back() const {
    return arr[sz - 1];
}

template <typename T>
size_t Vector<T>::size() const {
    return sz;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return cap;
}

template <typename T>
bool Vector<T>::empty() const { 
    return sz;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& vec) const {
    if (sz != vec.sz) {
        return false;
    }

    for (size_t i = 0; i < sz; ++i) {
        if (arr[i] != vec.arr[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& vec) const {
    return !this->operator==(vec);
}

template <typename T>
void Vector<T>::resize(size_t count, const T& value) {
    if (count < sz) {
        while (sz - count > 0) {
            pop_back();
        }
        return;
    }

    if (count > cap){
        reserve(count);
    }

    if (count > sz) {
        while (count - sz > 0) {
            push_back(value);
        }
    }

}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n <= cap) {
        return;
    }

    T* newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);

    try {
        std::uninitialized_copy(arr, arr + sz, newarr);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newarr);
        throw;
    }

    for (size_t i = 0; i < sz; ++i) {
        (arr + i)->~T();
    }

    delete[] reinterpret_cast<int8_t*>(arr);
    arr = newarr;
    cap = n;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (sz == cap) {
        reserve(2 * cap);
    }
    new(arr + sz) T(value);
    ++sz;
}

template <typename T>
void Vector<T>::pop_back() {
    (arr + sz - 1)->~T();
    --sz;
}

template <typename T>
void Vector<T>::clear() {
    while (sz > 0) {
        pop_back();
    }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    if (sz == 0) {
        while (cap > 0) {
            delete[] reinterpret_cast<int8_t*>(arr);
            --cap;
        }
        return;
    }

    reserve(sz);
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(const Args& ...args) {
    if (cap == sz) {
        reserve(2 * cap);
    }

    new (arr + sz) T(args...);
    ++sz;
}