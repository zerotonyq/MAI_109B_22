#include "List.hpp"
#include <iostream>
void List::print()
{
	Node* curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";

		if (curr == terminate_node)
			break;
		curr = curr->next;
	}
	std::cout << std::endl;
}
void List::insert(Node* prev, Node* n)
{
	if (prev == nullptr)
	{
		head = n;
		head->next = terminate_node;
		return;
	}
	Node* curr = head;
	while (curr != terminate_node)
	{
		if (curr == prev)
		{
			n->next = curr->next;
			curr->next = n;
			++size;
			return;
		}
		curr = curr->next;
	}
}
void List::erase(Node* n)
{
	Node* curr = head;
	Node* prev = nullptr;
	while (curr != terminate_node)
	{
		if (curr == n)
		{
			if (prev != nullptr)
			{
				prev->next = curr->next;
			}
			if (curr == head)
			{
				head = curr->next;
			}
			delete curr;
			curr = nullptr;
			--size;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}
size_t List::length()
{
	if (size != 0)
	{
		return size;
	}
	size_t sz = 0;
	Node* curr = head;
	while (curr != terminate_node)
	{
		++sz;
		curr = curr->next;
	}
	size = sz+1;
	return size;
}
List::List(Node* h, Node* terminate) : head{ h }, terminate_node{ terminate } {
	head->next = terminate;
};

void List::change_places()
{
	if (size < 4)
	{
		std::cout << "there must be at least 4 elements" << std::endl;
		return;
	}
	Node* second = head->next;
	Node* prev = nullptr;
	Node* cur = head;
	while (cur->next != terminate_node) {
		if (cur->next->next == terminate_node)
		{
			std::cout << "ok ";
			prev = cur;
		}
			
		cur = cur->next;
	}
	Node* third = second->next;
	Node* prelast = prev->next;
	head->next = prev->next;
	prev->next = second;
	head->next->next = third;
	second->next = terminate_node;
	
	std::cout << prev->value << " " << cur->value << " " << second->value << std::endl;
	
}
