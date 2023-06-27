#include "../include/ExpressionTree.hpp"

size_t ExpressionTree::get_priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

bool ExpressionTree::is_operator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool ExpressionTree::is_num(const std::string& elem) { 
    return elem.size() >= 2 || isdigit(elem[0]) || isalpha(elem[0]);
}

std::string ExpressionTree::to_postfix_form(const std::string& expression) {
    std::string postfix_form = "";
    myVector<std::string> temp_stack; 

    for (size_t i = 0; i < expression.size(); ++i) {
        char temp_char = expression[i];

        if (!is_operator(temp_char) && temp_char != ')' && temp_char != '(') {
            postfix_form += temp_char;
        } 
        else if (temp_char == '(') {
            std::string str;
            str.push_back(temp_char);
            temp_stack.push_back(str);
        } 
        else if (temp_char == ')') {
            while (temp_stack.back() != "(") {
                postfix_form += temp_stack.back();
                temp_stack.pop_back();
            }
            temp_stack.pop_back();
        } 
        else {
            int temp_char_priority = get_priority(temp_char);

            while (!temp_stack.empty() && (get_priority(temp_stack.back()[0]) >= temp_char_priority)) {
                postfix_form += temp_stack.back();
                temp_stack.pop_back();
            }
            
            std::string str;
            str.push_back(temp_char);
            temp_stack.push_back(str);
        }
    }

    while (!temp_stack.empty()) {
        postfix_form += temp_stack.back();
        temp_stack.pop_back();
    }

    return postfix_form;
}

void ExpressionTree::delete_branch(Node* node) {
    if (!node)
        return;
    delete_branch(node->get_left());
    delete_branch(node->get_right());
    delete node;
}

Node *ExpressionTree::create_branch(const std::string &expression) {
    if (expression.length() == 0)
        return nullptr;

    myVector<Node *> temp_stack;

    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '~') {
            Node *node_x = temp_stack.back();
            temp_stack.pop_back();

            Node *node = new Node("-", nullptr, node_x);
            temp_stack.push_back(node);
        } 
        else if (is_operator(expression[i])) {
            Node *node_x = temp_stack.back();
            temp_stack.pop_back();

            Node *node_y = temp_stack.back();
            temp_stack.pop_back();

            Node *node = new Node(std::string(1, expression[i]), node_y, node_x);
            temp_stack.push_back(node);
        } 
        else {
            temp_stack.push_back(new Node(std::string(1, expression[i])));
        }
    }

    return temp_stack.back();
}


ExpressionTree::ExpressionTree(const std::string &expression) {
    std::string postfix = to_postfix_form(expression);
    root = create_branch(postfix);
}


std::string ExpressionTree::transform_expression(Node* node, myVector<std::string>& nums) {
    if (node == nullptr) return "";

    std::string left = transform_expression(node->get_left(), nums);
    std::string right = transform_expression(node->get_right(), nums);

    if (is_num(node->get_token())) {
        nums.push_back(node->get_token());
        return node->get_token();
    } else {
        std::string elem2 = nums.back();
        nums.pop_back();
        std::string elem1 = nums.back();
        nums.pop_back();

        std::string result = calc_value(elem1, elem2, node->get_token());
        nums.push_back(result);

        if (left.empty() && right.empty()) {
            return result;
        } else {
            return left + " " + result + " " + right;
        }
    }
}

ExpressionTree::~ExpressionTree() {
    delete_branch(root);
}

Node *ExpressionTree::get_root() const {
    return root;
}

std::string ExpressionTree::calc_value(const std::string& elem1, const std::string& elem2, const std::string& oper) {
    int result = 0;
    if (oper == "+") {
        result = std::stoi(elem1) + std::stoi(elem2);
    }
    if (oper == "-") {
        result = std::stoi(elem1) - std::stoi(elem2);
    }
    if (oper == "*") {
        result = std::stoi(elem1) * std::stoi(elem2);
    }
    if (oper == "/") {
        result = std::stoi(elem1) / std::stoi(elem2);
    }    

    return std::to_string(result);
}

void ExpressionTree::search_sum(Node* node) {
    if (node == nullptr) return;

    search_sum(node->get_left());
    search_sum(node->get_right());

    if (node->get_token() == "+") {
        myVector<std::string> nums;
        std::string result = transform_expression(node, nums);
        if (nums.size() == 1) {
            Node* new_node = new Node(result);
            delete_branch(node->get_left());
            delete_branch(node->get_right());
            node->set_left(nullptr);
            node->set_right(nullptr);
            node->rewrite_node(new_node);
        }
    }
}

void ExpressionTree::print_expression(Node* root) {
    if (root == nullptr)
        return;

    print_expression(root->get_left());
    std::cout << root->get_token() << " ";
    print_expression(root->get_right());
}

void ExpressionTree::print_expression() {
    print_expression(root);
}

void ExpressionTree::task() {
    search_sum(root);
    print_expression();
}