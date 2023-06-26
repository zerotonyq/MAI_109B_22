#include "Node.hpp"
#pragma once
class List
{
public:
  Node* head;
  Node* terminate_node;
  List(Node* head, Node* terminate);
  void print();
  void insert(Node* prev, Node* n);
  void erase(Node* n);
  void change_places();
  size_t length();
private:
  size_t size = 0;
};

#include "../src/List.cpp"
