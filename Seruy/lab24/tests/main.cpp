#include "../include/Node.hpp"
#include "../include/ExpressionTree.hpp"

int main() { 

    std::string expression1 = "2 + 3";
    ExpressionTree tree1(expression1);
    tree1.task();
    std::cout << "\n\n\n";
    
    std::string expression2 = "2 + K + 4";
    ExpressionTree tree2(expression2);
    tree2.task();
    
    return 0;
}