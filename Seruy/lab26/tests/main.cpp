#include "../include/List.hpp"
#include "../src/benchmark.cpp"

int main() {
    
    List<int> myList;
    
    myList.push_front(5);
    myList.push_front(2);
    myList.push_front(8);
    myList.push_front(1);
    myList.push_front(4);

    std::cout << "Original list: ";
    myList.printList();

    myList.bubbleSort();

    std::cout << "Sorted list: ";
    myList.printList();

    bencmark();
    return 0;
}