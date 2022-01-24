#include <iostream>
#include <string>
#include "Ptica.h"

using namespace std;

class Golub : public Ptica
{
public:
	int brojNogu()
	{
		return 2;
	}
	string vrstaZivotinje()
	{
		return "Golub";
	}
};
