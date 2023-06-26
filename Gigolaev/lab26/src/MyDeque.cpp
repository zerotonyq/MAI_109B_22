#include "MyDeque.hpp"

template <typename T>
MyDeque<T>::MyDeque() {
    capacity = 8;
    front = -1;
    rear = 0;
    arr = new T[capacity];
}

template <typename T>
MyDeque<T>::~MyDeque() {
    delete[] arr;
}

template <typename T>
void MyDeque<T>::push_front(T x) {
    if (is_full()) {
        resize();
    }
    if (front == -1) {
        front = rear = 0;
    }
    else {
        front = (front - 1 + capacity) % capacity;
    }
    arr[front] = x;
}

template <typename T>
void MyDeque<T>::pop_front() {
    if (is_empty()) {
        cout << "Deque is empty!" << endl;
        exit(1);
    }
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % capacity;
    }
}

template <typename T>
void MyDeque<T>::push_back(T x) {
    if (is_full()) {
        resize();
    }
    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }
    arr[rear] = x;
}

template <typename T>
void MyDeque<T>::pop_back() {
    if (is_empty()) {
        cout << "Deque is empty!" << endl;
        exit(1);
    }
    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear = (rear - 1 + capacity) % capacity;
    }
}

template <typename T>
void MyDeque<T>::insert(int index, T value) {
    if (index < 0 || index > size()) {
        cout << "Index out of range!" << endl;
        exit(1);
    }
    if (is_full()) {
        resize();
    }
    if (index == size()) {
        push_back(value);
        return;
    }
    for (int i = size() - 1; i >= index; i--) {
        (*this)[i + 1] = (*this)[i];
    }
    (*this)[index] = value;
    rear = (rear + 1) % capacity;
}

template <typename T>
void MyDeque<T>::insert_order(T value) {
    if (is_empty() || value >= arr[rear]) {
        push_back(value);
        return;
    }
    if (value < arr[front]) {
        push_front(value);
        return;
    }
    int i = rear;
    while (value < arr[(i - 1 + capacity) % capacity]) {
        arr[i] = arr[(i - 1 + capacity) % capacity];
        i = (i - 1 + capacity) % capacity;
    }
    arr[i] = value;
    rear = (rear + 1) % capacity;
}

template <typename T>
void MyDeque<T>::insertion_sort() {
    for (int i = 1; i < size(); i++) {
        T key = (*this)[i];
        (*this).erase(i);
        (*this).insert_order(key);
    }
}

template <typename T>
void MyDeque<T>::erase(int index) {
    if (index < 0 || index >= size()) {
        cout << "Index out of range!" << endl;
        exit(1);
    }
    for (int i = index; i < size() - 1; i++) {
        (*this)[i] = (*this)[i + 1];
    }
    rear = (rear - 1 + capacity) % capacity;
}

template <typename T>
T& MyDeque<T>::operator[](int i) {
    if (i < 0 || i >= size()) {
        cout << "Index out of range!" << endl;
        exit(1);
    }
    return arr[(front + i) % capacity];
}

template <typename T>
int MyDeque<T>::size() {
    if (front == -1) {
        return 0;
    }
    return (rear - front + capacity) % capacity + 1;
}

template <typename T>
bool MyDeque<T>::is_empty() {
    return front == -1;
}

template <typename T>
bool MyDeque<T>::is_full() {
    return size() == capacity;
}

template <typename T>
void MyDeque<T>::resize() {
    T* tmp = new T[capacity * 2];
    int j = 0;
    for (int i = front; i != rear; i = (i + 1) % capacity) {
        tmp[j++] = arr[i];
    }
    tmp[j] = arr[rear];
    front = 0;
    rear = j;
    capacity = capacity * 2;
    delete[] arr;
    arr = tmp;
}

template <typename T>
void MyDeque<T>::print() {
    for (int i = 0; i < size(); i++) {
        cout << arr[(front + i) % capacity] << " ";
    }
    cout << endl;
}