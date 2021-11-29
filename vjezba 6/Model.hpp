#pragma once
#include <string>
#include <fstream>

using namespace std;

class HangmanModel {
	string movie;
	string guessMovie;
	string usedLetters;
	int lives = 8;
	bool inGame;
public:
	HangmanModel();
	string getMovie() const;
	string getGuessMovie() const;
	string getUsedLetters() const;
	int getLives();
	bool getInGame();
	void setGuessMovie(const std::string& guessMovie);
	void setUsedLetters(const std::string& usedLetters);
	void setLives();
	void setInGame(const bool inGame);
};
