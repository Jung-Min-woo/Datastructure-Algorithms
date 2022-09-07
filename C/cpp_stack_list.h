#ifndef __CPP_STACK_ARRAY_H__
#define __CPP_STACK_ARRAY_H__
#define STACK_LEN 100
#include <iostream>

template<typename Data>
class Node {
private:
	Data data;
	Node &next;
public:
	Node() { this->next = NULL; }
	Node(Data data) { this->data = data, this->next = NULL; }
	Node* GetNextNode() { return this->next; }
	void SetNextNode(Node &nextNode) { this->next = nextNode; }
	Data GetData() { return this->data; }
};
template<typename Data>
class Stack {
private:
	Node<Data> &head;
	int length;
public:
	Stack() { this->head = (Node<Data>*)NULL, length = 0; }
	bool isEmpty() { return this->length == 0 ? true : false;}
	void Push(Node<Data> &node_added){
		this->head.SetNextNode(this->head);
		this->head = node_added;
		this->length++;
	}
	Data Pop() {
		if (this->isEmpty()) exit(-1);
		delete this->head;
		this->head = this->head.next;
		this->length--; 
	}
	Data Peek() { 
		if (this->isEmpty()) exit(-1);
		else return this->head.GetData();
	}
};
#endif