#ifndef _TREE_HPP_INCLUDED
#define _TREE_HPP_INCLUDED

#include "Node.hpp"
#include "Stack.hpp"
#include <string>
#include <cmath>

class Tree {
private:
    Node* root = nullptr;

    void transform_expression(Node* root, Stack<std::string>& nums);
    void clear_tree(Node* node);
    void print_expression(Node* root);
    void search_substracts(Node* node);

public:
    void task();
    void print_expression();
    Tree() = default;
    Tree(const std::string& expression);
    ~Tree();
};

#include "../src/Tree.cpp"

#endif