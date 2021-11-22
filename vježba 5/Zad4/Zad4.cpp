#include <iostream>
#include <iomanip>
#include <time.h> 
#include <cmath>

using namespace std;
constexpr auto PI = 3.14;

class Target
{
	double x1; double y1; double x2; double y2;

public:
	Target(double = 0, double = 0, double = 0, double = 0);
	void setTarget(const double x1, const double y1, const double x2, const double y2);
	friend class Gun;
};
class Gun
{
	int number_of_bullet;
	double x, y;
public:
	Gun(int = 10000);
	void set_point();
	void setBullets(const int number_of_bullets);
	int rotate(Target& m);
};

Target::Target(double x1, double y1, double x2, double y2)
{
	x1 = rand() % 50 - 15;
	y1 = rand() % 50 - 15;
	x2 = rand() % 50 - 15;
	y2 = rand() % 50 - 15;
	setTarget(x1, y1, x2, y2);
}
void Target::setTarget(const double x1, const double y1, const double x2, const double y2)
{
	this->x1 = x1, this->y1 = y1;
	this->x2 = x2, this->y2 = y2;
}

void Gun::set_point()
{
	this->x = rand() % 50;
	this->y = rand() % 50;

}
Gun::Gun(int x) {
	setBullets(x);
	set_point();
}
void Gun::setBullets(const int x)
{
	this->number_of_bullet = x;
}

int Gun::rotate(Target& m)
{
	int x = this->x, y = this->y;
	int count = 1, n = unsigned(rand() % 10);
	if (this->number_of_bullet < n)
		return 0;
	this->number_of_bullet -= n;

	if (x > m.x1 and x <= m.x2 and y >= m.y1 and y <= m.y2)
		count++;
	if (x > m.x2 and x <= m.x1 and y >= m.y2 and y <= m.y1)
		count++;
	double angle = rand() % 360;
	double radians = angle * (PI / 180.0f);
	this->x = x * cos(radians) - y * sin(radians);
	this->y = x * sin(radians) + y * cos(radians);

	return count;
}

int main()
{
	srand(time(NULL));
	Gun g;
	int n = 1000;
	Target* t = new Target[n];
	int br = 0;
	for (int j = 0; j < n; j++)
	{
		int meta = 0;
		meta= g.rotate(t[j]);
		if (meta == 0) {
			cout << "Nema vise metaka" << endl;
			break;
		}
		if (meta == 2)
			br += (meta - 1);
	}
	cout << " " << endl;
	cout << "Pogodilo je: " << br << " meta" << endl;
	delete[] t;
}







