#include "../include/Iterator.hpp"

template <typename T>
Iterator<T>::Iterator(Node<T>* node) {
    this->node = node;
}

template <typename T>
T& Iterator<T>::operator*() {
    return node->data;
}

template <typename T>
Iterator<T> Iterator<T>::operator++() {
    node = node->next;
    return *this;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) {
    return node != other.node;
}
