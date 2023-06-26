#pragma once
#include <iostream>
struct Node {
    std::string data;
    Node* left = nullptr;
    Node* right = nullptr;
  ~Node()
  {
    if(left)
      delete left;
    if(right)
      delete right;
    data.clear();
  }
};
