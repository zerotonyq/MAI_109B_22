#pragma once
#include <iostream>
struct Node {
    std::string data;
    Node* left = nullptr;
    Node* right = nullptr;
  ~Node()
  {
    delete left;
    delete right;
  }
};
