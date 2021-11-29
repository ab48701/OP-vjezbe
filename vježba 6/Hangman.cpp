#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>


using namespace std;


class Hangman_Model {
public:
	int lives = 8;
	string str;
	string str_new;
};
class Hangman_View {
public:
	void displayProgress(Hangman_Model M);
	void displayUsedLetters(char c, int it, string& usedLettersC, string& usedLettersF);
	void displayHangman(Hangman_Model M);
};
class Hangman_Controller {
public:
	void userEntry(char& c);
	void checkLetter(char c, Hangman_Model& M, int& it);
	void updateLives(Hangman_Model M);
	void gameStatus(Hangman_Model M, char& c);
};


void Hangman_Controller::updateLives(Hangman_Model M)
{
	cout << "\nImate još" << M.lives << " života!" << endl;
}
void Hangman_Controller::userEntry(char& c)
{
	cout << "Unestie slovo ili broj: " << endl;
	cin >> c;
	if (!isalpha(c) || !isdigit(c))
		while (!isalpha(c) && !isdigit(c))
		{
			cout << "Pogrešan unos! " << endl;
			cout << "Unesite slovo ili broj : " << endl;
			cin >> c;
		}
}
void Hangman_Controller::checkLetter(char c, Hangman_Model& M, int& it)
{
	char cc;
	it = M.str.find(c);
	if (it < 0)
	{
		it = M.str.find(toupper(c));
		if (it < 0)
			M.lives--;
		else
			for (int i = 0; i < M.str.size(); i++)
			{
				cc = c;
				if (isupper(M.str[i]))
				{
					if (M.str[i] == toupper(cc)) {
						cc = toupper(cc);
						swap(M.str_new[i], cc);
					}
				}
				cc = c;
				if (M.str[i] == c)
					swap(M.str_new[i], cc);
			}
	}
	else
		for (int i = 0; i < M.str.size(); i++)
		{
			cc = c;
			if (isupper(M.str[i]))
			{
				if (M.str[i] == toupper(cc)) {
					cc = toupper(cc);
					swap(M.str_new[i], cc);
				}
			}
			cc = c;
			if (M.str[i] == c)
				swap(M.str_new[i], cc);
		}
}
void Hangman_Controller::gameStatus(Hangman_Model M, char& c)
{
	if (M.str == M.str_new)
		cout << "\n\nPogodili ste!" << endl;
	if (M.lives == 0 || M.str == M.str_new)
	{
		cout << "\nŽelite li nastaviti?" << endl;
		cout << "Unesite  Y za nastavak, N za kraj: " << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "Pogrešan unos!" << endl;
			cout << "Unesite Y za nastavak, N za kraj:" << endl;
			cin >> c;
		}
	}
}

void Hangman_View::displayHangman(Hangman_Model M)
{
	if (M.lives == 8)
		return;
	if (M.lives == 7)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
	}
	if (M.lives == 6)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
	}
	if (M.lives == 5)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << " |" << endl;
	}
	if (M.lives == 4)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|" << endl;
	}
	if (M.lives == 3)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
	}
	if (M.lives == 2)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ " << endl;
	}
	if (M.lives == 1)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ \\" << endl;
	}
	if (M.lives == 0)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ \\" << endl;
		cout << "Izgubili ste! " << endl;
	}
}
void Hangman_View::displayProgress(Hangman_Model M)
{
	cout << "Trenutno stanje : " << M.str_new << endl;
}
void Hangman_View::displayUsedLetters(char c, int it, string& usedLettersC, string& usedLettersF)
{
	int brC = 0, brF = 0;
	for (int i = 0; i < usedLettersC.size(); i++)
		if (c == usedLettersC[i])
			brC++;
	for (int i = 0; i < usedLettersF.size(); i++)
		if (c == usedLettersF[i])
			brF++;
	if (it < 0 && brF == 0) {
		usedLettersF += c;
		usedLettersF += ',';
	}
	else if (it >= 0 && brC == 0) {
		usedLettersC += c;
		usedLettersC += ',';
	}
	cout << "Koristili ste točna slova: " << usedLettersC << endl << "Koristili ste netočna slova: " << usedLettersF << endl;
}

void main()
{
	Hangman_View V;
	Hangman_Model M;
	Hangman_Controller C;
	int it;
	fstream fp;
	int play = 0;
	string usedLettersC, usedLettersF;
	char c{};
	int seek = 0;
	fp.open("movies.txt");

	while (fp)
	{
		getline(fp, M.str);
		M.lives = 8;
		usedLettersC.clear();
		usedLettersF.clear();
		M.str_new.clear();
		for (int i = 0; i < M.str.size(); i++)
		{
			if (!isalpha(M.str[i]) && !isdigit(M.str[i]))
				M.str_new += M.str[i];
			else
				M.str_new += '*';
		}
		for (M.lives; M.lives != 0 && M.str != M.str_new;)
		{
			C.updateLives(M);
			C.userEntry(c);
			C.checkLetter(c, M, it);
			V.displayProgress(M);
			V.displayUsedLetters(c, it, usedLettersC, usedLettersF);
			V.displayHangman(M);
			C.gameStatus(M, c);
		}
		if (c == 'y')
		{
			if (M.lives == 0)
			{
				cout << "Želite  li probati istu rečenicu?" << endl;
				cout << "Unesite  Y za nastavak, N za kraj: " << endl;
				cin >> c;
				while (c != 'y' && c != 'n')
				{
					cout << "Pogrešan unos!" << endl;
					cout << "Unesite  Y za nastavak, N za kraj" << endl;
					cin >> c;
				}
				if (c == 'y')
					fp.seekg(seek);
				else
					seek += M.str.size();
			}
			else
				seek += M.str.size();
		}
		else
			break;
	}
}