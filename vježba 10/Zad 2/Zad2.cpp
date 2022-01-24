#include<iostream>
#include "Zad2.h"

using namespace std;

int main() {
	Stack<int>  integerStack;

	cout << "Uklonjen zadnji element iz stacka: " << integerStack.pop() << endl;
	cout << "Uklonjen zadnji element iz stacka: " << integerStack.pop() << endl;
	cout << "Uklonjen zadnji element iz stacka: " << integerStack.pop() << endl;


	integerStack.push(155);
	integerStack.push(589);
	integerStack.push(953);

	if (integerStack.isEmpty()) {
		cout << "Stack je prazan !" << endl;
	}

	integerStack.push(1000);

	if (integerStack.isEmpty() == 0) {
		cout << "Stack nije prazan!" << endl;
	}

	return 0;
}

