#include <iostream>

using namespace std;

template <typename temp>
void sortArr(temp* arr, int n)
{
	int c;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}



template <typename temp>

void sortArr(char* arr, int n)
{
	char c;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (tolower(arr[i]) < tolower(arr[j]))
			{
				c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}



int main()
{
	int arr[] = { 1,5,56,45,64,2 };
	int n = sizeof(arr) / sizeof(int);


	char arr2[] = { 'G','H','f','s','z','a','A'};
	int n2 = sizeof(arr2) / sizeof(char);

	sortArr<char>(arr2, n2);
}
