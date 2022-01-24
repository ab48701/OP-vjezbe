#pragma once
#include<iostream>
#include <string>

using namespace std;

template <class StackType> class Stack {
private:
	int top;
	StackType stack[5];
public:
	Stack();
	StackType pop();
	void push(StackType k);
	bool isEmpty();
};
template <class StackType> Stack<StackType>::Stack() {
	top = -1;
}
template <class StackType> StackType Stack<StackType>::pop() {
	StackType poppedElement = stack[top];
	top--;
	return poppedElement;
}
template <class StackType> void Stack<StackType>::push(StackType k) {
	top = top + 1;
	stack[top] = k;
}
template <class StackType> bool Stack<StackType>::isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}


