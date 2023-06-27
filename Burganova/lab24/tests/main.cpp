#include "../include/Tree.hpp"

int main() {
    std::string expression = "5+3-1";

    Tree tree(expression);
    tree.task();
}