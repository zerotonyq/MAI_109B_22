#include "../include/Stack.hpp"

template <typename T>
size_t Stack<T>::get_size() const {
    return vector.size();
}

template <typename T>
void Stack<T>::pop() {
    vector.pop_back();
}

template <typename T>
bool Stack<T>::empty() const {
    return vector.size() == 0;
}

template <typename T>
void Stack<T>::push(const T& value) {
    vector.push_back(value);
}

template <typename T>
void Stack<T>::clear() {
    vector.clear();
}

template <typename T>
T& Stack<T>::peek() {
    return vector.back();
}

template <typename T>
const T& Stack<T>::peek() const {
    return vector.back();
}
