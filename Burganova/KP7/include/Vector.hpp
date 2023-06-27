#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {
private:
    size_t sz;
    size_t cap;
    T* arr;

public: 
    Vector();
    Vector(size_t);
    Vector(std::initializer_list<T>);
    Vector(const Vector&); 
    Vector& operator=(const Vector<T>&);
    ~Vector(); 

    T& operator[](size_t);
    T& at(size_t);
    T& front();  
    T& back(); 
    const T& operator[](size_t) const;
    const T& at(size_t) const;
    const T& front() const; 
    const T& back() const; 

    size_t size() const;
    size_t capacity() const;

    bool empty() const;
    bool operator==(const Vector<T>&) const; 
    bool operator!=(const Vector<T>&) const; 

    void resize(size_t, const T&); 
    void reserve(size_t);
    void push_back(const T&);
    void pop_back();
    void clear(); 
    void shrink_to_fit(); //

    template <typename... Args>
    void emplace_back(const Args& ...args); //

};


#include "../src/Vector.cpp"

#endif