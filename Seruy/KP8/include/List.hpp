#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <iostream>

enum MyEnum {
    VALUE1,
    VALUE2,
    VALUE3,
    VALUE4,
    VALUE5,
    VALUE6,
    VALUE11,
    VALUE22,
    VALUE33,
    VALUE44,
    VALUE55,
    VALUE66,
    VALUE12,
    VALUE23,
    VALUE34,
    VALUE45,
    VALUE56,
    VALUE67,
    VALUE14,
    VALUE25,
    VALUE36,
    VALUE47,
    VALUE58,
    VALUE69
};

template <typename T, typename Allocator = std::allocator<T>>
class List {
private:
    class Node {
    public:
        T value;
        Node* next = nullptr;

        Node(const T& value);
        Node(const T& value, Node* next);
    };

    using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;

    Node* head_ptr = nullptr;
    Node* const block_element_ptr = AllocTraits::allocate(alloc, 1);
    size_t size = 0;

public:
    class Iterator;

    size_t get_size() const;

    List() = default;
    List(const T& value);
    ~List();

    void push_front(const T& value);
    void pop_front();
    void insert(const T& value, Iterator& it);
    void erase(Iterator& iter);
    void erase(Iterator& first_iterator, Iterator& second_iterator);

    std::ostream& operator<<(std::ostream& stream);

    class Iterator {    
    public:
        Node* current_node_ptr = nullptr;

        Iterator(Node& node);

        Iterator& operator=(Node* node_ptr);
        Iterator& operator++();

        T& operator*();
        const T& operator*() const ;

        bool operator!=(const Iterator& iterator) const;
        bool operator==(const Iterator& iterator) const; 
    };

    Iterator begin() const;
    Iterator end() const;
};

#include "../src/List.cpp"

#endif