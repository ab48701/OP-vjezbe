#include <iostream>

using namespace std;

void find_max_min(int arr[], int len, int& min, int& max) {

	min = arr[0];
	max = arr[0];

	for (int i = 0; i < len; i++) {

		if (arr[i] < min) 
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
}


int main() {

	int min;
	int max;
	int len;

	cout << "Unesite duzinu niza:" << endl;
	cin >> len;

	int* arr = new  int[len];

	for (int i = 0; i < len; i++)
	{
		cout << "Unesite brojeve:"<< endl;
		cin >> arr[i];

	}
	find_max_min(arr, len, min, max);
	cout << "max: " << max << endl;
	cout <<"min: " << min << endl;

}








