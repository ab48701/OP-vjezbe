#include "Model.hpp"
#include "Controller.hpp"
#include <iostream>
#include <string>
using namespace std;

void HangmanController::userEntry(HangmanModel& model) {
	char letter;
	cin >> letter;
	checkLetter(letter, model);
}

void HangmanController::checkLetter(char letter, HangmanModel& model) {
	string movie = model.getMovie();
	string usedLetters = model.getUsedLetters();
	string guessMovie = model.getGuessMovie();
	int movieWordSize = movie.size();

	letter = toupper(letter);

	usedLetters.erase(remove(usedLetters.begin(), usedLetters.end(), letter), usedLetters.end());
	model.setUsedLetters(usedLetters);

	for (int i = 0; i < movieWordSize; i++) {
		if (guessMovie[i] == letter && usedLetters.find(letter) == string::npos) 
			model.setInGame(false);                                                              
			break;
		}
		else if (movie.find(letter) == string::npos)  
			model.setInGame(false);
			break;
		}
		else if (model.getMovie()[i] == letter) 
			guessMovie[i] = letter;
			model.setInGame(true);
		}
	}
	model.setGuessMovie(guessMovie);
}

void HangmanController::updateLives(HangmanModel& model) {
	if (!model.getInGame()) {
		model.setLives();
	}
}

bool HangmanController::checkIfGameIsOver(HangmanModel& model) {
	return (model.getGuessMovie() == model.getMovie()) ? 0 : model.getLives();
}
