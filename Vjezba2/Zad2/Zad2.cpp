#include <iostream>
#include <iomanip>

using namespace  std;


int& find_index(int arr[], int index) 
{

	return arr[index];
}

int main()
{
	int len;
	int index;

	cout << "Unesite duzinu niza:" << endl;
	cin >> len;

	int* arr = new  int[len];
	cout << "Upisite i-ti element niza koji zelite  uvecati za 1" << endl;
	cin >> index;


	for (int i = 0; i < len; i++) {

		cout << "Unesite brojeve:" << endl;
		cin >> arr[i];
	}
				
		find_index(arr, index) += 1;
		for (int i = 0; i < len; i++) {

		cout <<"Uvecani niz:"<< arr[i] << endl;
		
	}
	
}
	


