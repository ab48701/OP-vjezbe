#include <iostream>
#include "Vector.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include "../Vector.h"

using namespace std;
using std::vector;


int element_removal(vector<int>& vec)
{
    int n;

    cout << "Upišite element iz vekotora koji zelite ukloniti " << endl;
    cin >> n;

    vec.erase(vec.begin() + n);

    print(vec);
}

int main()
{
    vector<int> vec;
    int n = 5;

    input(vec, n);
    element_removal(vec);
}