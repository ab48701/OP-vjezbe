#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
	T* arr;
	size_t size;
	size_t capacity;
public:
	Stack(size_t Capacity);
	~Stack() { delete[]arr; }
	void push(const T& element);
	void pop();
	bool is_empty();
};

template <typename T>
Stack<T>::Stack(size_t Capacity)
{
	arr = new T[Capacity];
	size = 0;
	capacity = Capacity;
}

template <typename T>
void Stack<T>::push(const T& element)
{
	if (size == capacity)
	{
		capacity *= 2;
		int* newArr = new T[capacity];
		for (int i = 0; i < capacity - 1; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
	arr[size] = element;
	size++;
}

template <typename T>
void Stack<T>::pop()
{
	if (size == 0)
		return;
	else
	{
		size--;
	}
}

template <typename T>
bool Stack<T>::is_empty()
{
	return size;
}
