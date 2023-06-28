#include "../tests/benchmark.cpp"
#include "../include/List.hpp"

int main() {
    // Create a list with 30 elements
    List<int> myList;
    for (int i = 0; i < 30; ++i) {
        myList.push_front(i);
    }

    List<int>::Iterator it = myList.begin();
    List<int>::Iterator end = myList.end();
    for (int i = 0; i < 10; ++i) {
        ++it;
    }
    List<int>::Iterator rangeStart = it;
    for (int i = 0; i < 9; ++i) { 
        ++it;
    }
    List<int>::Iterator rangeEnd = it;

    myList.erase(rangeStart, rangeEnd);

    // Print the modified list
    for (List<int>::Iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n\n";

    benchmark();
    return 0;
}
