#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Node.hpp"
#pragma once

template <typename T>
class Iterator {
private:
    Node<T>* node;

public:
    Iterator(Node<T>* node);

    T& operator*();
    Iterator<T> operator++();
    bool operator!=(const Iterator<T>& other);
};

#include "../src/Iterator.cpp"
#endif
