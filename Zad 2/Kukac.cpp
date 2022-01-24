#include <iostream>
#include <string>
#include "Kukac.h"

using namespace std;

class Mrav : public Kukac 
{
public:
	int brojNogu()
	{
		return 6;
	}
	string vrstaZivotinje()
	{
		return "Mrav";
	}
};
