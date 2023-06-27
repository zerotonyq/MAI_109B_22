#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node {
private:
    std::string token;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    Node() = default;
    ~Node() = default;
    Node(const std::string& data);
    Node(const std::string& data, Node *_left, Node *_right);
    std::string get_token() const;
    Node* get_left() const;
    Node* get_right() const;
    void set_left(Node* node);
    void set_right(Node* node);
    void rewrite_node(Node* temp_node);
};
#include "../src/Node.cpp"
#endif