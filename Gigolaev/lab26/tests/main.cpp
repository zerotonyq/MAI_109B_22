﻿#include "../include/MyDeque.hpp"

int main() {
    MyDeque<int> int_dq;
    MyDeque<char> char_dq;
    int_dq.push_back(7);
    int_dq.push_front(4);
    int_dq.push_back(2);
    int_dq.push_front(5);
    int_dq.push_back(1);
    int_dq.push_back(3);
    int_dq.push_back(7);

    int_dq.print(); // Output: 5 4 2 1 3

    int_dq.insertion_sort();

    int_dq.print(); // Output: 1 2 3 4 5

    return 0;
}
