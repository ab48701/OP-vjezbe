#include<iostream>
#include "Zad2.h"

using namespace std;

int main()
{
	int n = 5;
	Stack<int> stack(n);

	for (int i = 0; i < n; i++)
	{
		stack.push(i);
	}

	if (stack.is_empty())
	{
		cout << "Stack not empty";
	}
	else
	{
		cout << "Stack empty";
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		stack.pop();
	}

	if (stack.is_empty())
	{
		cout << "Stack not empty";
	}
	else
	{
		cout << "Stack empty";
	}
}
