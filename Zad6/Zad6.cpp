#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;
using std :: vector;



void rev_sort(vector <string>& str)
{
	string str1;
	for (int i = 0; i < 5; i++)
	{
		cout << "unesite string" << endl;
		cin >> str1;
		str.push_back(str1);
	}
	for (int i = 0; i < str.size(); i++)
	{
		reverse(str[i].begin(), str[i].end());
	}
	sort(str.begin(), str.end());
}

int main()
{
	vector <string> str;
	rev_sort(str);
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}
