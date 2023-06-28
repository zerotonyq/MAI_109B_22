#ifndef LIST_HPP
#define LIST_HPP
#include "../../KP8/include/List.hpp"

template <typename T, typename Allocator = std::allocator<T>>
class List {
private:
    class Node {
    public:
        bool operator>(const Node& other) const;
    };
public:
    bool isEmpty() const;
    void printList() const;
    void bubbleSort();
};
#include "../../KP8/src/List.cpp"
#include "../src/List.cpp"

#endif