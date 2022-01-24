#include <iostream>
#include <string>
#include "Pauk.h"

using namespace std;

class CrnaUdovica : public Pauk
{
public:
	int brojNogu()
	{
		return 8;
	}
	string vrstaZivotinje()
	{
		return "Crna Udovica";
	}
};
