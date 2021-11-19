#include <iostream>
#include "Vector.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
using std::vector;

void  new_vector(vector<int>& vec3)
{
	vector<int> vec1;
	vector<int> vec2;
	cout << "Unesite elemente 1. i 2. vektora" << endl;
	int n1, n2;
	cin >> n1 >> n2;
	input(vec1, n1);
	input(vec2, n2);
	cout << "Unesite raspon:" << endl;
	int lower, upper;
	border(vec1, lower, upper);
	border(vec2, lower, upper);
	vector<int> ::iterator it;
	for (it = vec1.begin(); it != vec1.end(); ++it)
	{
		int cnt = count(vec2.begin(), vec2.end(), *it);
		if (!cnt)
			vec3.push_back(*it);

	}

}
int main()
{
	vector<int>vec3;
	new_vector(vec3);
	cout << "Novi vektor:";
	for (int i = 0; i < vec3.size(); ++i)
	{
		cout << vec3.at(i) << "";
	}
}