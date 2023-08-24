#pragma once

#include <cstddef>
#include <iostream>
#include "../include/Node.hpp"

class Tree {
public:
    void prefixTraversalPrint(Node* root);
    Node* constructTree(std::string postfix);
private:
    std::string infixToPostfix(std::string infix);
    int getOperatorWeight(char op);
    int hasHigherPrecedence(char op1, char op2);
    bool isOperator(char c);
    bool isOperand(char c);
    Node* createNode(char c);
    
};
#include "../src/Tree.cpp"
