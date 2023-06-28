#include <chrono>
#include <forward_list>

void bencmark(){
    std::cout << "Comparing my List and List from STL";

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    List<int> myListInt;
    std::forward_list<int> stdListInt;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Push_front: (Test on integer values: stdlist/mylist)" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        stdListInt.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    
    begin = std::chrono::steady_clock::now();
    for(int i = 0; i < 1000000; ++i){
        myListInt.push_front(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    std::cout << std::endl;

    std::cout << "Pop_front: (Test on integer values: stdlist/mylist)" << std::endl;
    
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