#ifndef DEQUE_HPP_INCLUDED
#define DEQUE_HPP_INCLUDED
#include <iostream>
#include "Node.hpp"

#pragma once

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;
    size_t deq_size;
public:
    Deque();
    ~Deque();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool empty();
    size_t size();
    void bubble_sort();
    T& front_element();
    T& back_element();
    template <class U> friend std::ostream& operator<<(std::ostream& os, const Deque<U>& deque);
};
#include "../src/Deque.cpp"
#endif
