#include "../include/Deque.hpp"
#pragma once
template <typename T>
Deque<T>::Deque() {
    front = nullptr;
    rear = nullptr;
    deq_size = 0;
}

template <typename T>
Deque<T>::~Deque() {
    while (front != nullptr) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Deque<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    deq_size++;
}

template <typename T>
void Deque<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    deq_size++;
}

template <typename T>
void Deque<T>::pop_front() {
    if (front == nullptr) {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }
    Node<T>* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    } else {
        front->prev = nullptr;
    }
    delete temp;
    deq_size--;
}

template <typename T>
void Deque<T>::pop_back() {
    if (rear == nullptr) {
        std::cout << "Deque is empty!" << std::endl;
        return;
    }
    Node<T>* temp = rear;
    rear = rear->prev;
    if (rear == nullptr) {
        front = nullptr;
    } else {
        rear->next = nullptr;
    }
    delete temp;
    deq_size--;
}

template <typename T>
bool Deque<T>::empty() {
    return deq_size == 0;
}

template <typename T>
size_t Deque<T>::size() {
    return deq_size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& deque) {
    if (deque.front == nullptr) {
        os << "Deque is empty!";
        return os;
    }
    Node<T>* current = deque.front;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

template <typename T>
void Deque<T>::bubble_sort() {
    Node<T>* current;
    Node<T>* next = nullptr;
    bool swapped;
    if (front == nullptr)
        return;
    do {
        swapped = false;
        current = front;
        while (current->next != next) {
            if (current->data > current->next->data) {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        next = current;
    } while (swapped);
}

template <typename T>
T& Deque<T>::front_element() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    return front->data;
}

template <typename T>
T& Deque<T>::back_element() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    return rear->data;
}