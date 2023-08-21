#ifndef MY_DEQUE_HPP
#define MY_DEQUE_HPP

#include <iostream>

template <typename T>
class MyDeque {
private:
    size_t capacity;
    int64_t front;
    int64_t rear;
    T* arr;

public:
    MyDeque();
    ~MyDeque();

    void push_front(T x);
    void pop_front();
    void push_back(T x);
    void pop_back();

    void insert(int64_t index, T value);
    void insert_order(T value, int64_t rear_bound);
    void insertion_sort();
    void erase(int64_t index);

    T& operator[](int64_t i);

    size_t size() const;
    bool is_empty() const;
    bool is_full() const;
    void resize();

    void print() const;
    void print_full() const;
};

#include "../src/MyDeque.cpp"
#endif // MY_DEQUE_HPP
