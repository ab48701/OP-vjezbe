#include "ComputerPlayer.h"



int ComputerPlayer::computer_move()
{
	srand(time(NULL));
	vector<int> m{ 0, 1,2,5,3,6,7,8 }; 
	int i = 8; 
	cout << i << endl;
	return i;
}
int ComputerPlayer::rand_broj()
{
	int i, j;
	srand(time(NULL));
	int c = 3;
	int sum;
	if (c == 0)
		sum = 0;
	else if (c == 1)
	{
		sum = rand() % kovanice.size(); 
	}
	else if (c == 2)
	{
		i = rand() % kovanice.size();
		j = rand() % kovanice.size();
		sum = i + j;
	}
	else if (c == 3)
	{
		sum = 8;
	}
	return sum;
}