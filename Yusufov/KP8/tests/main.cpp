#include <iostream>
#include "../include/List.hpp"
#include "../include/Iterator.hpp"
#include "../src/List.cpp"
#include "../include/Node.hpp"
#include "../src/Node.cpp"
#include "../src/benchmark.cpp"
#include <list>

int main() {
    LinkedList<int64_t> linkedList;

    int choice;
    int k, key, new_data;
    bool exit = false;

    while (!exit) {
        std::cout << "Choose:" << std::endl;
        std::cout << "1. Exclude the last K elements of a list" << std::endl;
        std::cout << "2. Delete elements" << std::endl;
        std::cout << "3. Add element in end" << std::endl;
        std::cout << "4. Show elements in a list" << std::endl;
        std::cout << "5. Show the length of the list" << std::endl;
        std::cout << "6. Start benchmark" << std::endl;
        std::cout << "7. Add new element in beginning" << std::endl;
        std::cout << "8. Delete first element" << std::endl;
        std::cout << "9. Delete last element" << std::endl;
        std::cout << "10. Exit" << std::endl;
        std::cout << "Your choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the number of items to exclude: ";
                std::cin >> k;
                linkedList.excludeLastK(k);
                break;

            case 2:
                std::cout << "Enter the element to delete: ";
                std::cin >> key;
                linkedList.deleteNode(key);
                break;

            case 3:
                std::cout << "Enter the value of the new element: ";
                std::cin >> new_data;
                linkedList.push_front(new_data);
                break;

            case 4:
                std::cout << "List content: " << linkedList << std::endl;
                break;

            case 5:
                std::cout << "Length of the list: " << linkedList.getListLength() << std::endl;
                break;

            case 6:
                runBenchmark();
                break;

            case 7:
                std::cout << "Enter new element: ";
                std::cin >> new_data;
                linkedList.push_back(new_data);
                break;

            case 8:
                linkedList.pop_back();
                break;

            case 9:
                linkedList.pop_front();
                break;

            case 10:
                exit = true;
                break;
            default:
                std::cout << "Uncorrect choice" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
