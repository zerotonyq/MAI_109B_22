#include <iostream>
#include <chrono>

template<typename DequeType>
void benchmark(int number) {
    DequeType deque;
    std::cout << "benchmark " << number << " elements" << std::endl;
    
    // push_back elements
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < number; i++) {
        deque.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "push_back time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]\n";
    
    // pop_back elements
    start = std::chrono::high_resolution_clock::now();
    while (!deque.empty()) {
        deque.pop_back();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "pop_back time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]\n";
    
    // push_front elements
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < number; i++) {
        deque.push_front(i);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "push_front time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]\n";

    // pop_front elements
    start = std::chrono::high_resolution_clock::now();
    while (!deque.empty()) {
        deque.pop_front();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "pop_front time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]\n";
}