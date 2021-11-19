#include <iostream>
#include "Vector.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

void input(vector<int>& vec, int& n)
{
	int x;

	cout << "Unesi duzinu vektora:" << endl;
	cin >> n;
	cout << "Unesi elemente:" << endl;

	for (int i = 0; i < n; i++) 
	{
		cin >> x;
		vec.push_back(x);
	}
}
void border(vector<int>& vec, int& lower, int& upper)
{
	int x;

	cout << "Unesi donju granicu intervala:" << endl;
	cin >> lower;
	cout << "Unesi gornju granicu intervala:" << endl;
	cin >> upper;

	cout << "Unesi elemente:" << endl;
	cin >> x;


	while (lower <= x && x <= upper)
	{
		vec.push_back(x);

		cin >> x;
	}
}
void print(vector<int>& vec) 
{
	for (it i = vec.begin(); i != vec.end(); i++) 
	{
		cout << *i << " ";
	}
	cout << endl;
}

	int main() 
	{
		int n = 0, lower = 0, upper = 0;
		vector<int> vec1;

		input(vec1, n);
		print(vec1);
		vec1.clear();

		border(vec1, lower, upper);
		print(vec1);
		vec1.clear();

	}