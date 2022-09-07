#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "cpp_stack_list.h"
#include <iostream>

int main(void) {
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);
	Node<int> n4(4);
	Node<int> n5(5);
	Stack<int> *s = new Stack<int>();
	s->Push(n1);
	s->Push(n2);
	s->Push(n3);
	s->Push(n4);
	s->Push(n5);

	printf("Peek Data : %d\n", s->Peek());
	//while (SIsEmpty(s) == FALS) printf("%d\n", SPop(s));
	return 0;
}