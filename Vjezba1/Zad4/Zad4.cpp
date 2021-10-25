#include <iostream>

using namespace std;


int find_min_rec(int arr[], int n)
{

	if (n == 1)
		return arr[0];
	return min(arr[n - 1], find_min_rec(arr, n - 1));
}


int find_max_rec(int arr[], int n)
{


	if (n == 1)
		return arr[0];
	return max(arr[n - 1], find_max_rec(arr, n - 1));
}


int main()
{
	int arr[] = { 1, 4, 45, 6, 50, 10, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "najveci:" << find_max_rec(arr, n) << endl;
	cout << "najmanji: " << find_min_rec(arr, n) << endl;
	return 0;
}
