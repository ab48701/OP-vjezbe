#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

class Dot
{
public:
	double x = 0, y = 0, z = 0;
	void setDot()
	{
	cout << "unesite vrijednost kordinata:" << endl;
		cin >> x >> y >> z;
	}
	void randomDot(int a, int b)
	{
		srand(time(NULL));
		x = (double)(a + rand() % (b - a) + 1);
		y = (double)(a + rand() % (b - a) + 1);
		z = (double)(a + rand() % (b - a) + 1);
	}
	void getDot()
	{
		cout << "Unesite kordinate:";
		cin >> x >> y >> z;
	}
	double distance2D(Dot D1, Dot D2)
	{
		return sqrt(pow(D2.x - D1.x, 2) + pow(D2.y - D1.y, 2));
	}
	double distance3D(Dot D1, Dot D2)
	{
		return sqrt(pow(D2.x - D1.x, 2) + pow(D2.y - D1.y, 2) + pow(D2.z - D1.z, 2));
	}
};

int main()
{
	Dot  D1, D2;

	
	D1.getDot();
	D2.getDot();

	cout << "Distance in 2D space is: " << D1.distance2D(D1, D2) << endl;
	cout << "Distance in 3D space is: " << D1.distance3D(D1, D2) << endl;
}