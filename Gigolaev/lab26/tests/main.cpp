#include "../include/MyDeque.hpp"

template<typename T>
void Print_dq(MyDeque<T>* dq)
{
    std::cout << std::endl << "unsorted deque: " << std::endl;
    dq->print();
    dq->insertion_sort();
    std::cout << std::endl << "sorted deque: " << std::endl;
    dq->print();
}
MyDeque<int>* Test_1()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_back(9);
    dq->push_front(1);
    dq->push_front(2);
    dq->push_front(4);
    dq->insert(2, 3);
    dq->push_back(2);
    dq->push_front(5);
    dq->push_back(1);
    dq->erase(5);
    return dq;
}
MyDeque<int>* Test_2()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_back(9);
    dq->push_front(1);
    dq->push_front(2);
    dq->push_front(4);
    dq->insert(2, 3);
    dq->push_back(2);
    dq->push_front(5);
    dq->push_back(1);
    dq->erase(5);
    dq->push_back(9);
    dq->push_front(1);
    dq->push_front(2);
    dq->push_front(4);
    dq->insert(2, 3);
    dq->push_back(2);
    dq->push_front(5);
    dq->push_back(1);
    dq->erase(5);
    return dq;
}
MyDeque<int>* Test_3()
{
    MyDeque<int>* dq = new MyDeque<int>();
    return dq;
}
MyDeque<int>* Test_4()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->insert(0, 1);
    return dq;
}
MyDeque<int>* Test_5()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    dq->push_back(1);
    return dq;
}
MyDeque<int>* Test_6()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    dq->push_front(2);
    return dq;
}
MyDeque<int>* Test_7()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_front(7);
    dq->push_front(6);
    dq->push_front(5);
    dq->push_front(4);
    dq->push_front(3);
    dq->push_front(2);
    dq->push_front(1);
    dq->push_front(0);
    return dq;
}
MyDeque<int>* Test_8()
{
    MyDeque<int>* dq = new MyDeque<int>();
    dq->push_back(7);
    dq->push_back(6);
    dq->push_back(5);
    dq->push_back(4);
    dq->push_back(3);
    dq->push_back(2);
    dq->push_back(1);
    dq->push_back(0);
    return dq;
}
int main() {
    MyDeque<int>* dq;
    dq = Test_1();
    Print_dq(dq);
    delete dq;
    dq = Test_2();
    Print_dq(dq);
    delete dq;
    dq = Test_3();
    Print_dq(dq);
    delete dq;
    dq = Test_4();
    Print_dq(dq);
    delete dq;
    dq = Test_5();
    Print_dq(dq);
    delete dq;
    dq = Test_6();
    Print_dq(dq);
    delete dq;
    dq = Test_7();
    Print_dq(dq);
    delete dq;
    dq = Test_8();
    Print_dq(dq);
    delete dq;
    return 0;
}