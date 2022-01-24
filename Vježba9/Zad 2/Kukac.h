#pragma once
#include <iostream>
#include <string>
#include "Zivotinja.h"

using namespace std;

class Kukac : public Zivotinja
{
public:
	int brojNogu()
	{
		return 6;
	}
	string vrstaZivotinje()
	{
		return "Kukac"
	}
};
