#pragma once
#include <iostream>
#include "Zivotinja.h"

class Brojac
{
private:
	int zbrojNogu = 0;
public:
	void getZivotinja(Zivotinja&);
	void printZbrojNogu();
};
