#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <string>
#include <iostream>
#include "Tree.hpp"

class Tree;

class Node {
    friend class Tree;
private:
    std::string value;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node() = default;
    Node(const std::string& value, Node* left, Node* right);
    Node(const std::string& value);
};

#include "../src/Node.cpp"

#endif