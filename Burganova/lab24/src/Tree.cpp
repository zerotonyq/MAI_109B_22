#include "../include/Tree.hpp"

size_t get_priority(const std::string& c) {
    if (c == "+" || c == "-") {
        return 1;
    } else if (c == "*" || c == "/") {
        return 2;
    }

    return 0;
}

bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool is_num(std::string& elem) {
    return elem.size() >= 2 || isdigit(elem[0]) || isalpha(elem[0]);
}

std::string& to_postfix(const std::string& expression) {
    std::string postfix = "";
    Stack<std::string> stack;

    for (size_t i = 0; i != expression.size(); ++i) {
        char c = expression[i];

        if (!is_operator(c) && c != '(' && c != ')') { 
            postfix.push_back(c);
        } else if (c == '(') {
            std::string s;
            s.push_back(c);
            stack.push(s);
        } else if (c == ')'){
            while (stack.peek() != "(") {
                postfix += stack.peek();
                stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.empty() && (get_priority(stack.peek()) >= get_priority(std::to_string(c)))) {
                postfix += stack.peek();
                stack.pop();
            }
            std::string s;
            s.push_back(c);
            stack.push(s);
        }
    }

    while (!stack.empty()) {
        postfix += stack.peek();
        stack.pop();
    }
    return postfix;
}

Tree::Tree(const std::string& expression) {
    std::string postfix = to_postfix(expression);

    if (postfix.length() == 0) {
        root = nullptr;
        return;
    }

    Stack<Node*> stack;

    for (char c: postfix){
        if (c == '~'){
            Node* node_x = stack.peek();
            stack.pop();

            Node* node = new Node("-", nullptr, node_x);
            stack.push(node);
        } else if (is_operator(c)) {
            Node* node_x = stack.peek();
            stack.pop();

            Node* node_y = stack.peek();
            stack.pop();

            std::string s;
            s.push_back(c);
            Node* node = new Node(s, node_y, node_x);
            stack.push(node);
        } else {
            std::string s;
            s.push_back(c);
            stack.push(new Node(s));
        }
    }

    root = stack.peek();
}

Tree::~Tree() {
    clear_tree(root);
}

void Tree::clear_tree(Node* node) {
    if (node == nullptr) {
        return;
    }

    clear_tree(node->left);
    clear_tree(node->right);
    delete node;
}

std::string& calc_value(std::string& el1, std::string& el2, std::string& oper) {
    int res;
    if (oper == "+") {
        res = std::stoi(el1) + std::stoi(el2);
    }
    if (oper == "-") {
        res = std::stoi(el1) - std::stoi(el2);
    }
    if (oper == "*") {
        res = std::stoi(el1) * std::stoi(el2);
    }
    if (oper == "/") {
        res = std::stoi(el1) / std::stoi(el2);
    }    
    
    std::string result = std::to_string(res);
    return result;
}

void Tree::transform_expression(Node* node, Stack<std::string>& nums) {
    if (node == nullptr) return;

    transform_expression(node->left, nums);
    transform_expression(node->right, nums);

    if (is_num(node->value)) {
        nums.push(node->value);
    } else {
        std::string el2 = nums.peek();
        nums.pop();
        std::string el1 = nums.peek();
        nums.pop();
        node->left = nullptr;
        node->right = nullptr;
        node->value = calc_value(el1, el2, node->value);
        nums.push(node->value);
    }
}

void Tree::search_substracts(Node* node) {
    if (node == nullptr) return;

    search_substracts(node->left);
    search_substracts(node->right);
    if (node->value == "-") {
        Stack<std::string> nums;
        transform_expression(node, nums);
    }
}

void Tree::print_expression(Node* root) {
    if (root == nullptr)
        return;

    print_expression(root->left);
    std::cout << root->value << " ";
    print_expression(root->right);
}

void Tree::print_expression() {
    print_expression(root);
}

void Tree::task() {
    search_substracts(root);
    print_expression();
}