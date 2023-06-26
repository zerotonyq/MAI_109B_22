#ifndef MY_DEQUE_HPP
#define MY_DEQUE_HPP

#include <iostream>

using namespace std;

template <typename T>
class MyDeque {
private:
    int capacity;
    int front;
    int rear;
    T* arr;

public:
    MyDeque();
    ~MyDeque();

    void push_front(T x);
    void pop_front();
    void push_back(T x);
    void pop_back();

    void insert(int index, T value);
    void insert_order(T value);
    void insertion_sort();
    void erase(int index);

    T& operator[](int i);

    int size();
    bool is_empty();
    bool is_full();
    void resize();

    void print();
};

#include "../src/MyDeque.cpp"
#endif // MY_DEQUE_HPP
