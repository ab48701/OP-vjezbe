#pragma once
#include <iostream>
#include <string>
#include "Zivotinja.h"

using namespace std;

class Ptica : public Zivotinja
{
public:
	int brojNogu()
	{
		return 2;
	}
	string vrstaZivotinje()
	{
		return "Ptica"
	}
};
