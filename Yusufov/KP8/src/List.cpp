#include "../include/List.hpp"
#include <iostream>
#pragma once

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* new_node = new Node<T>(data);
    new_node->next = head;
    head = new_node;
}
template <typename T>
void LinkedList<T>::excludeLastK(int k) {
    if (head == nullptr) {
        std::cout << "Список пуст." << std::endl;
    }

    Node<T>* current = head;
    Node<T>* prev = nullptr;

    int count = 0;
    while (current != nullptr) {
        if (count >= k) {
            prev->next = nullptr;
            delete current;
            break;
        }
        prev = current;
        current = current->next;
        count++;
    }

    if (count < k) {
        std::cout << "В списке меньше " << k << " элементов." << std::endl;
    }
}

template <typename T>
void LinkedList<T>::deleteNode(T key) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;

    if (current != nullptr && current->data == key) {
        head = current->next;
        delete current;
    }

    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Элемент не найден в списке." << std::endl;
    }

    prev->next = current->next;
    delete current;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    Node<T>* node = list.head;
    while (node != nullptr) {
        os << node->data << " ";
        node = node->next;
    }
    return os;
}


template <typename T>
int LinkedList<T>::getListLength() {
    int length = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

template <typename T>
Iterator<T> LinkedList<T>::begin() {
    return Iterator<T>(head);
}

template <typename T>
Iterator<T> LinkedList<T>::end() {
    return Iterator<T>(nullptr);
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    Node<T>* new_node = new Node<T>(data);
    
    if (!head) {
        head = new_node;
        return;
    }

    Node<T>* current = head;
    while (current->next) {
        current = current->next;
    }
    
    current->next = new_node;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (!head) {
        std::cout << "Empty" << std::endl;
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;
    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (!head) {
        std::cout << "Empty" << std::endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}
