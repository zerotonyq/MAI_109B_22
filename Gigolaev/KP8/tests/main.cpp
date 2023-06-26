#include <iostream>
#include "List.hpp"
int main()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    List* l = new List(a, new Node('c'));

    l->print();
    std::cout << l->length() << std::endl;
    l->insert(a, b);
    l->insert(b, new Node('d'));
    l->insert(b, new Node('e'));
    l->print();
    std::cout << l->length() << std::endl;
    //l->erase(a);
    l->print();
    std::cout << l->length() << std::endl;
    l->change_places();
    l->print();

}
