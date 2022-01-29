#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


bool veci_od_500(int i)
{
	return (i > 500);
}

bool manji_od_300(int i)
{
	return (i < 300);
}
int findMin(std::vector<int> vec)
{
	return *min_element(vec.begin(), vec.end());
}

int findMax(std::vector<int> vec)
{
	return *max_element(vec.begin(), vec.end());
}

bool silazno(int i, int j) {

	return i > j;

};


int main()
{

	ifstream fd("numbers.txt");
	try
	{
		if (!fd.is_open())
		{
			throw string("Ne postoji datoteka");
		}
	}
	catch (string x)
	{
		cout << x << endl;
	}
	vector<int> vec;
	istream_iterator<int> it1(fd), it2;
	ostream_iterator<int> os(cout, "\n");
	copy(it1, it2, back_inserter(vec));
	cout << "brojevi veci 500 = " << count_if(vec.begin(), vec.end(), veci_od_500) << endl;
	cout << "Max = " << findMax(vec) << endl;
	cout << "Min = " << findMin(vec) << endl;
	vec.erase(remove_if(vec.begin(), vec.end(), manji_od_300), vec.end());
	sort(vec.begin(), vec.end(), silazno);
	copy(vec.begin(), vec.end(), os);
}
