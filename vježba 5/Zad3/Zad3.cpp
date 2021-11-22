#include <iostream>
#include <iomanip>

using namespace std;

class Dot
{
public:
	 double x, y, z;
};


class Target
{
	public:
	Dot bottomLeft, topRight;

	void targetHit(Dot bottomLeft, Dot topRight, Dot shot)
	{
		if ((shot.x >= bottomLeft.x) && (shot.x <= topRight.x)
			&& (shot.y >= bottomLeft.y) && (shot.y <= topRight.y)
			&& (shot.z >= bottomLeft.z) && (shot.z <= topRight.z))
			cout << "Target hit" << endl;
		else
			cout << "Target missed" << endl;
	}
};

int main()
{
	Dot botL, topR, shot;
	Target t1;
	cout << "unestite donju lijevu tocku:" ;
	cin >> botL.x;
	cout << "botL.x:";
	cin >> botL.y;
	cout << "botL.y:";
	cin >> botL.z;
	cout << "botL.z:";
	cout << "unestite gornju desnu tocku:";
	cin >> topR.x;
	cout << "topR.x:";
	cin >> topR.y;
	cout << "topR.y:";
	cin >> topR.z;
	cout << "topR.z:";
	t1.targetHit(botL, topR, shot);

}