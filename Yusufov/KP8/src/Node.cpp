#include "../include/Node.hpp"
#pragma once

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    next = nullptr;
}
