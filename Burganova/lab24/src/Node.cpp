#include "../include/Node.hpp"

Node::Node(const std::string& value): value(value) {}

Node::Node(const std::string& value, Node* left, Node* right): value(value), left(left), right(right) {}