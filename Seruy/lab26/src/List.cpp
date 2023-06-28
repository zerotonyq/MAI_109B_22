#include "../include/List.hpp"
#include "../../KP8/src/List.cpp"

template <typename T, typename Allocator>
bool List<T, Allocator>::Node::operator>(const Node& other) const {
    return value > other.value;
}

template <typename T, typename Allocator>
bool List<T, Allocator>::isEmpty() const {
    return head_ptr == nullptr;
}

template <typename T, typename Allocator>
void List<T, Allocator>::printList() const {
    Node* current = head_ptr;
    while (current != nullptr) {
        std::cout << current->value << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T, typename Allocator>
void List<T, Allocator>::bubbleSort() {
    if (head_ptr == nullptr || head_ptr->next == nullptr) {
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* current = head_ptr;
        Node* previous = nullptr;
        Node* next_node = current->next;
        while (next_node != nullptr) {
            if (*current > *next_node) {
                if (previous != nullptr) {
                    previous->next = next_node;
                } else {
                    head_ptr = next_node;
                }
                current->next = next_node->next;
                next_node->next = current;
                previous = next_node;
                next_node = current->next;
                swapped = true;
            } else {
                previous = current;
                current = current->next;
                next_node = current->next;
            }
        }
    } while (swapped);
}