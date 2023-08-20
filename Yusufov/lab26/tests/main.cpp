#include <iostream>
#include "../include/Deque.hpp"
#include "../src/benchmark.cpp"
#include <deque>

int main() {
    Deque<int64_t> myDeque;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Benchmark launching:" << std::endl;
    int n = 100000, k = 3;
    while (k--) {
        std::cout << "Custom Deque ";
        benchmark<Deque<int64_t>>(n);
        std::cout << "----------------------------------------------\n";
        std::cout << "std::deque ";
        benchmark<std::deque<int64_t>>(n);
        std::cout << "----------------------------------------------\n";
        n *= 10;
        return 0;
    }
}