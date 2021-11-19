#include <iostream>
#include "Vector.h"
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

void sort_zero_and_sum(vector<int>& v)
{
    sort(v.begin(), v.end());
    vector<int>::iterator it = min_element(v.begin(), v.end());
    v.insert(it, 0);
    int sum = 0;
    for (it = v.begin(); it != v.end(); ++it)
    {
        sum += *it;
    }
    v.push_back(sum);
}
int main()
{
    vector<int> v{ 44,21,78,33,124,255,91,13,7,54 };
    sort_zero_and_sum(v);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }

}