#include "Game.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"


void Game::igraj()
{
	int n;
	int bodoviH = 0;
	int bodoviC = 0; 
	ComputerPlayer cp;
	HumanPlayer hp;
	Player* HumanPlayer = &hp;
	Player* ComputerPlayer = &cp;
	while (1)
	{
		int sum = HumanPlayer->rand_broj() + ComputerPlayer->rand_broj();
		cout << "Pogodite iznos:" << endl << "Player: ";
		cin >> n;
		if (n == sum)
		{
			cout << "Pogodili ste, imate bod!" << endl;
			bodoviH++;
		}
		else if (n != sum)
		{
			cout << "Pogrešno" << endl;
		}
		cout << "Pogodite iznos" << endl << "Computer: ";
		int m = cp.computer_move();
		if (m == sum)
		{
			cout << "Pogodili ste, imate bod!" << endl;
			bodoviH++;
		}
		else if (m != sum)
		{
			cout << "Pogrešno" << endl;
		}


		if (bodoviH == bodovi)
		{
			cout << "Pobjedili ste!!!!" << endl;
			break;
		}
		else if (bodoviC== bodovi)
		{
			cout << "Izgubili ste ,Kompjuter je pobjedio" << endl;
			break;
		}
	}
}