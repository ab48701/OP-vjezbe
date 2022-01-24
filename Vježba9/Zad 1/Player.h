#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Player {
private:
	vector <int> kovanice{ 1,2,5 };
public:
	virtual int rand_broj() = 0;
};


