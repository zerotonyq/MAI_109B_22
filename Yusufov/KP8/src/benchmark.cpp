#include <iostream>
#include <chrono>
#include <list>
#include "../include/List.hpp"

void runBenchmark() {
    const int sizes[] = {100000, 1000000, 10000000};

    for (int size : sizes) {
        std::cout << "Benchmark for size: " << size << std::endl;

        // Benchmark for push_back
        {
            std::cout << "Push Back:" << std::endl;

            LinkedList<int> myLinkedList;
            std::list<int> stdLinkedList;

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                myLinkedList.push_back(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "My LinkedList: " << duration.count() << " seconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                stdLinkedList.push_back(i);
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "std::list: " << duration.count() << " seconds" << std::endl;
        }

        {
            std::cout << "Push Front:" << std::endl;

            LinkedList<int64_t> myLinkedList;
            std::list<int64_t> stdLinkedList;

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                myLinkedList.push_front(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "My LinkedList: " << duration.count() << " seconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                stdLinkedList.push_front(i);
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "std::list: " << duration.count() << " seconds" << std::endl;
        }
        {
            std::cout << "Pop back:" << std::endl;

            LinkedList<int64_t> myLinkedList;
            std::list<int64_t> stdLinkedList;

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                myLinkedList.pop_back();
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "My LinkedList: " << duration.count() << " seconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                stdLinkedList.pop_back();
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "std::list: " << duration.count() << " seconds" << std::endl;
        }
        {
            std::cout << "Pop Front:" << std::endl;

            LinkedList<int64_t> myLinkedList;
            std::list<int64_t> stdLinkedList;

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                myLinkedList.pop_front();
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "My LinkedList: " << duration.count() << " seconds" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                stdLinkedList.pop_front();
            }
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            std::cout << "std::list: " << duration.count() << " seconds" << std::endl;
        }

        std::cout << std::endl;
    }
    return;
}