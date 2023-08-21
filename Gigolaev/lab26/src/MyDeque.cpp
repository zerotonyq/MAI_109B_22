#include "MyDeque.hpp"

template <typename T>
MyDeque<T>::MyDeque() {
    capacity = 1;
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
        std::cout << "Deque is empty!" << std::endl;
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
        std::cout << "Deque is empty!" << std::endl;
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
void MyDeque<T>::insert(int64_t index, T value) {
    if (index < 0 || index > static_cast<int>(size()) || 
    (index == static_cast<int64_t>(size()) && index == 1)) {
        std::cout << "Index out of range! (insert)" << std::endl;
        exit(1);
    }
    if (is_full()) {
        resize();
    }
    if (index == static_cast<int64_t>(size())) {
        push_back(value);
        return;
    }
    MyDeque<T> dc;
    for(int64_t i = 0; i <= index; ++i)
    {
        dc.push_back(arr[front]);
        pop_front();
    }
    push_front(value);
    for(int64_t i = 0; i <= index; ++i)
    {
        push_front(dc.arr[dc.rear]);
        dc.pop_back();
    }
    
}

template <typename T>
void MyDeque<T>::insert_order(T value, int64_t index) {
    if (is_empty() || value >= arr[(front+index-1)%capacity]) {
        insert(index-1, value);
        return;
    }
    else if (value < arr[front]) {
        
        push_front(value);
        return;
    }
    int64_t i = index-1;
    while (value < arr[(i+front)%capacity]) {
        --i;
    }
    insert(i, value);
}

template <typename T>
void MyDeque<T>::insertion_sort() {
    for (int64_t i = 1; i < static_cast<int64_t>(size()); i++) {
        T key = (*this)[i];
        (*this).erase(i);
        (*this).insert_order(key, i);
    }
}

template <typename T>
void MyDeque<T>::erase(int64_t index) {
    if (index < 0 || index >= static_cast<int64_t>(size())) {
        std::cout << "Index out of range!" << std::endl;
        exit(1);
    }
    for (int64_t i = index; i < static_cast<int64_t>(size()-1); i++) {
        (*this)[i] = (*this)[i + 1];
    }
    rear = (rear - 1 + capacity) % capacity;
}

template <typename T>
T& MyDeque<T>::operator[](int64_t i) {
    if (i < 0 || i >= static_cast<int64_t>(size())) {
        std::cout << "Index out of range!(operator []) " << i << std::endl;
        exit(1);
    }
    return arr[(front + i) % capacity];
}

template <typename T>
size_t MyDeque<T>::size() const{
    if (front == -1) {
        return 0;
    }
    return static_cast<size_t>((rear - front + capacity) % capacity + 1);
}

template <typename T>
bool MyDeque<T>::is_empty() const {
    return front == -1;
}

template <typename T>
bool MyDeque<T>::is_full() const{
    return size() == capacity;
}

template <typename T>
void MyDeque<T>::resize(){
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
void MyDeque<T>::print() const{
    std::cout << std::endl << "----------------" << std::endl;
    for(int64_t i = 0; i < static_cast<int64_t>(size()); ++i)
        std::cout << i << " ";
    std::cout << " - indexes"<< std::endl;
    for (int64_t i = 0; i < static_cast<int64_t>(size()); i++) {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << " - values";
    std::cout << std::endl << "----------------" << std::endl;
}

template <typename T>
void MyDeque<T>::print_full() const{
    for(size_t i = 0; i < capacity; ++i)
        std::cout << i << " ";
    std::cout << std::endl;
    for (size_t i = 0; i < capacity; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "front - " << front << std::endl;
    std::cout << "rear - " << rear << std::endl;
    std::cout << "size - " << size() << std::endl;
    std::cout << "capacity - " << capacity << std::endl;
}