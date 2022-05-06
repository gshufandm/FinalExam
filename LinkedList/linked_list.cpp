
#include "linked_list.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T> 
LinkedList<T>::~LinkedList(){
	int size = this -> numItems;
	for(int i = size-1; i >= 0; i--){
		Node<T> *cur = get_node(i);
		delete cur;
	}
}

template <typename T> 
void LinkedList<T>::push_back(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;
	
	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	tail->next = n;
	n->prev = tail;
	tail = n;	
}


template <typename T>
void LinkedList<T>::push_front(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;

	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	head->prev = n;
	n->next = head;
	head = n;
}

template <typename T>
void LinkedList<T>::insert(size_t pos ,T item){
	if(pos<0 || pos > numItems){
		throw invalid_argument("cannot insert at this idx");
	}
	if(pos == 0){
		push_front(item);
	}
	else if(pos == numItems){
		push_back(item);
	}
	else{
		Node<T> *n = new Node<T>;
		n->data = item;
		Node<T> *front = get_node(pos-1);
		Node<T> *back = get_node(pos);
		n -> prev = front;
		n -> next = back;
		front -> next = n;
		back -> prev = n;
		numItems++;
	}
}


template <typename T>
T LinkedList<T>::at(size_t idx){
	if(idx >= numItems){
		throw std::invalid_argument("List index out of range: " + std::to_string(idx));
	}

	Node<T> *n = get_node(idx);
	return n->data;
}


template <typename T>
Node<T> *LinkedList<T>::get_node(size_t idx){

	size_t i = 0;
	Node<T> *cur = head;
	while(i < idx){
		cur = cur->next;
		i++;
	}

	return cur;
}



