#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"
#include <ostream>
#pragma once


template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList();
    ~LinkedList();

    void pop_front();
    void pop_back();
    void push_back(T data);
    void push_front(T data);
    void excludeLastK(int k);
    void deleteNode(T key);
    int getListLength();

    Iterator<T> begin();
    Iterator<T> end();
    
    template <class U> friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);
};

#include "../src/List.cpp"
#endif
