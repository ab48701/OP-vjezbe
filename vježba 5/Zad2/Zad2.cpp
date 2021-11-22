#include <iostream>
#include <iomanip>
#include <time.h> 


using namespace std;


class Dot
{
public:
	double x; double y; double z;

	
	void setDot(const double x, const double y, const double z);
	Dot(double x, double y, double z);
};

class Gun
{
	Dot d;
	int magazine;
	int bullets;

public:
	Gun(int = 0, int = 0);
	void setBullets(const int magazine, int bullets);
	void shoot(int x);
	void reload() { this->bullets = magazine; };
};

Dot::Dot(double x, double y, double z)
{
	cout << "Unesi kordinate x,y,z" << endl;
	cin >> x;
	cin >> y;
	cin >> z;
	setDot(x, y, z);
}
void Dot::setDot(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Gun::Gun(int x, int y)
{

	setBullets(x, y);
}
void Gun::setBullets(const int x, int y)
{
	this->magazine = x;
	this->bullets = y;
}
void Gun::shoot(int x)
{
	if (this->bullets < x)
	{
		reload();
	}
	this->bullets -= x;
	if (this->bullets == 0)
		reload();
}

int main()
{
	Gun g(30, 15);
	int x;
	cout << "Koliko zelis metaka ispucati, ako zelis stati Ctrl+Z" << endl;
	while (cin >> x)
	{
		g.shoot(x);
	}
}



