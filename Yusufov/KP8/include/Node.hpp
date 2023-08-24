#ifndef NODE_HPP
#define NODE_HPP
#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data);
};

#include "../src/Node.cpp"
#endif
