#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value);
};

#include "../src/Node.cpp"
#endif