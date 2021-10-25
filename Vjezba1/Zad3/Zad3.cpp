#include <iostream>

using namespace std;


int find_max(int arr[], int n)
{


	int max = arr[0];


	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}


int find_min(int arr[], int n)
{

	int min = arr[0];

	for (int i = 1; i < n; i++)
		if (arr[i] < min)
			min = arr[i];

	return min;
}


int main()
{
	int arr[] = { 10, 324, 45, 90, 98 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Najveci " << find_max(arr, n) << endl;
	cout << "Najmanji " << find_min(arr, n) << endl;

	return 0;
}