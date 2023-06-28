#include "../include/List.hpp"
#include <forward_list>
#include <chrono>

void benchmark() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List<MyEnum> myListEnum;
    std::forward_list<MyEnum> stdListEnum;
    List<int> myListInt;
    std::forward_list<int> stdListInt;

    std::cout << "Push_front: (1.ENUM: stdlist/mylist; 2.INT: stdlist/mylist)" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    //stdlistenum
    for(int i = VALUE1; i < VALUE69; ++i){
        stdListEnum.push_front(static_cast<MyEnum>(i));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    //mylistenum
    begin = std::chrono::steady_clock::now();
    for(int i = VALUE1; i < VALUE69; ++i){
        myListEnum.push_front(static_cast<MyEnum>(i));
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    ///stdlistint
    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        stdListInt.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    ///mylistint
    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        myListInt.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;

    std::cout << "Pop_front: (1.ENUM: stdlist/mylist; 2.INT: stdlist/mylist)" << std::endl;
    begin = std::chrono::steady_clock::now();
    for(int i = VALUE1; i < VALUE69; ++i){
        stdListEnum.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(int i = VALUE1; i < VALUE69; ++i){
        myListEnum.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        stdListInt.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;


    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        myListInt.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << std::endl;
    return;
}