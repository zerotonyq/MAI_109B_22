#ifndef TREE_HPP
#define TREE_HPP

#include "../../../lab23/include/MyVector.hpp"
#include "Node.hpp"
#include <iostream>

class ExpressionTree {
private:
    Node *root = nullptr;

    size_t get_priority(char c);
    bool is_operator(char c);
    bool is_num(const std::string& elem);

    std::string to_postfix_form(const std::string& expression);
    std::string calc_value(const std::string& elem1, const std::string& elem2, const std::string& oper); 
    Node *create_branch(const std::string &postfix);

    std::string transform_expression(Node* root, myVector<std::string>& nums); 
    void delete_branch(Node *node);
    void print_expression(Node* root);
    void search_sum(Node* node); 

public:
    ExpressionTree() = default;
    ExpressionTree(const std::string &expression);
    ~ExpressionTree();

    Node *get_root() const;
    
    void print_expression();
    void task();
};

#include "../src/ExpressionTree.cpp"
#endif