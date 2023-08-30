#pragma once
#include <iostream>
class Node
{
    public:
        Node* left;
        Node* right;
        std::pair<int32_t, std::string> val;
};