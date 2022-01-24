#include <iostream>


using namespace std;


template <class SortArr>
void Sort(SortArr* arr,  size_t  n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				SortArr Object_item;
				Object_item = arr[i];
				arr[i] = arr[j];
				arr[j] = Object_item;

			}
		}
	}
}


int main()
{
	char array[5] = { 'g','e','k','l','m' };

	Sort(array, 5);
	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}