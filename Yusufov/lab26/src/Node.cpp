#include "../include/Deque.hpp"

template <typename T>
Node<T>::Node(const T& value) {
    data = value;
    prev = nullptr;
    next = nullptr;
}
