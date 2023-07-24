#pragma once
#include <iostream>
#include "Data.h"
template <typename Type>
class LinkedList
{
private:
	struct Node {
		Type value;
		Node* nextNode;
		
	};
	Node* new_node(Type _value, Node* _nextNode) {
		Node* temp = new Node();
		temp->value = _value;
		temp->nextNode = _nextNode;
		return temp;
	}
	Node* new_node() {};
	Node* head;
	Node* tail;
	size_t size;

public:
	size_t set_size(size_t _size) {
		size = _size;
	}
	size_t get_size() {
		return size;
	}
	LinkedList(Type* array, size_t _size) {
		size = _size;
		for (int i = 0; i < _size; i++) {
			push_back(array[i]);
		}
	}
	LinkedList() {
		head = new Node;
		head->nextNode = nullptr;
		tail = head;
		size = 0;
	};
	LinkedList(std::initializer_list<Type>array) {
		for (auto x = array.begin(); x != array.end(); x++)
		{
			push_back(*(x));
		}
	}
	Node* get(size_t index) {
		Node* new_node = head;
		for (size_t i = 0; i < index; i++)
		{
			new_node = new_node->nextNode;
			if (new_node == nullptr)
			{
				return tail;
			}
		}
		return new_node;
	}
	//¬ставка элементов 
	Node* push_back(Type value) {
		if (!size) {
			head = new_node(value, nullptr);
			tail = head;
			size++;
			return tail;
		}
		else {
			Node* temp = new_node(value, nullptr);
			tail->nextNode = temp;
			this->tail = temp;
			size++;
			return tail;
		}
	}
	Node* push_head(Type value) {
		Node* temp_node = new Node();
		if (head == nullptr) {
			temp_node = push_back(value);
		}
		else {
			temp_node = new_node(value, head);
			head = temp_node;
		}
		size++;
		return temp_node;
	}
	Node* pop() {
		if (!size) {
			return nullptr;
		}
		else {
			this->head = head->nextNode;
			size--;
		}
		return head;
	}
	Node* pop_back() {
		Node* temp_node = new Node();
		if (head == nullptr) {
			return nullptr;
		}
		else if (head == tail) {
			head = new_node();
			tail = head;
			size--;
			return tail;
		}
		else {
			temp_node = tail;
			tail->nextNode = get(size - 2);
			size--;
			return temp_node;
		}

	}
	Node* remove(size_t index) {


		if (!size) {
			return;
		}
		else if (head == tail) {
			head = new_node();
			tail = head;
			size = 0;
		}
		else if (!index) {
			pop();
		}
		else if (index == size - 1) {
			pop_back();
		}
		else {
			Node* temp_node = get(index - 1);
			Node* help_node = get(index);
			temp_node->nextNode = help_node->nextNode;
			size--;
			return help_node;
		}
	}
	Node* insert(Type value, size_t index) {
		Node* ins_node = new Node(value); //добавл€ема€ €чейка
		Node* temp_node = get(index); // €чейка, чье место украли
		Node* help_node = get(index - 1); // €чейка, что помен€ет свою ссылку
		if (head == nullptr) {
			push_back(value);
		}
		else if (head == tail) {
			push_head(value);
		}
		else if (index == 0) {
			push_head(value);
		}
		else if (index == size - 1) {
			push_head(value);
		}
		else {
			ins_node->nextNode = temp_node;
			help_node->nextNode = ins_node;
		}
		size++;
		return ins_node;
	}
	void print() {
		for (size_t i = 0; i < size; i++)
		{
			std::cout << get(i)->value << " ";
		}
		std::cout << std::endl;
	}
	
	friend std::ostream& operator<<(std::ostream& cout, LinkedList<Type>& list) {
		for (size_t i = 0; i < list.get_size(); i++)
		{
			cout << list.get(i)->value;
		}
		
		return cout;
	}

	friend std::ostream& operator<<(std::ostream& cout, Node* node) {

		cout << node->value;
		return cout;
	}
	Type operator[](size_t index) {
		return get(index)->value;
	}
};

