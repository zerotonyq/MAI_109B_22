#include "../../lab23/include/Vector.hpp"
#include <locale.h>
#include "../include/Tree.hpp"
#include "../include/Node.hpp"



int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");
    std::string infix;
    std::cout << "type infix: ";
    getline(std::cin, infix);
    Tree tree;
    Node* root = tree.constructTree(infix);

    std::cout << "here if postfix tree: ";
    tree.prefixTraversalPrint(root);

    std::cout << std::endl;
    delete root;
    
    return 0;
}
