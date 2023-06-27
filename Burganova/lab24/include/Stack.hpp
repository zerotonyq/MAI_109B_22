#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include "../../KP7/include/Vector.hpp"

template <typename T>
class Stack {
private:
    Vector<T> vector;

public:
    size_t get_size() const;
    bool empty() const;

    void pop();
    void push(const T& value);
    void clear();

    T& peek();
    const T& peek() const;
};

#include "../src/Stack.cpp"

#endif  