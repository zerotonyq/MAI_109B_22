#include "../include/Node.hpp"

Node::Node(const std::string& data) : token(data) {}
Node::Node(const std::string& data, Node *_left, Node *_right) : token(data), left(_left), right(_right) {}

std::string Node::get_token() const {
    return token;
}

Node *Node::get_left() const {
    return left;
}

Node* Node::get_right() const {
    return right;
}

void Node::set_left(Node* node) {
    left = node;
}

void Node::set_right(Node* node) {
    right = node;
}

void Node::rewrite_node(Node *temp_node) {
    token = temp_node->get_token(); 
    left = temp_node->get_left(); 
    right = temp_node->get_right(); 
}