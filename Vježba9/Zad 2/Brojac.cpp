#include <iostream>
#include <string>
#include "brojac.h"


using namespace std;

void Brojac::getZivotinja(Zivotinja& zivotinja)
{
	cout << "Dodano": << zivotinja.vrstaZivotinje() << "\n";
	zbrojNogu += zivotinja.brojNogu();
}

void Brojac::printZbrojNogu()
{
	cout << "Zbroj nogu je : " << zbrojNogu;
}