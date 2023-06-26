#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <locale.h>
#include "../include/Vector.hpp"
#include "../include/Node.hpp"

int getOperatorWeight(char op) {
    int weight = -1;

    switch (op) {
    case '+':
    case '-':
        weight = 1;
        break;
    case '*':
    case '/':
        weight = 2;
        break;
    case '^':
        weight = 3;
        break;
    }

    return weight;
}

int hasHigherPrecedence(char op1, char op2) {
    int op1Weight = getOperatorWeight(op1);
    int op2Weight = getOperatorWeight(op2);

    if (op1Weight == op2Weight) {
        return true;
    }

    return op1Weight > op2Weight;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

std::string infixToPostfix(std::string infix) {
  std::stack<char> opStack;
  std::string postfix;

    for (size_t i = 0; i < infix.length(); ++i) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!opStack.empty() && opStack.top() != '(' && hasHigherPrecedence(opStack.top(), c)) {
                postfix += opStack.top();
                opStack.pop();
            }

            opStack.push(c);
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }

            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop();
            }
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

Node* createNode(char c) {
  Node* node = new Node();
  node->data = c;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* constructTree(std::string postfix) {
  std::stack<Node*> stk;
  Node* waiting = nullptr;
  for (size_t i = 0; i < postfix.length(); ++i) {
    char c = postfix[i];
    
    if (isOperand(c)) {
      Node* node = createNode(c);
      stk.push(node);
    }
    else {
      
      Node* node = createNode(c);
      
      node->right = stk.top();
      stk.pop();
      
      node->left = stk.top();
      stk.pop();
      
      stk.push(node);
      if (c == '^')
	{
	  int val = stoi(node->right->data) * -1;
	  node->right->data = std::to_string(val);
                waiting = node;
	}
      else if (c == '/' && waiting)
	{
	  node->data = '*';
	  waiting = nullptr;
	}
    }
  }
    //std::std::cout << stk.size() << " " << stk.top()->data;
    return stk.top();
}

void prefixTraversalPrint(Node* root) {
    if (root == NULL) {
        return;
    }

    std::cout << root->data << " ";
    prefixTraversalPrint(root->left);
    prefixTraversalPrint(root->right);
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");
    std::string infix;
    std::cout << "type infix: ";
    getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    //std::cout << postfix << std::endl;
    Node* root = constructTree(postfix);

    std::cout << "here if postfix tree: ";
    prefixTraversalPrint(root);

    std::cout << std::endl;
    delete root;
    return 0;
}
