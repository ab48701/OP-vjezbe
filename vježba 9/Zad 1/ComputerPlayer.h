#pragma once
#include "Player.h"

class ComputerPlayer : public Player {
public:
	int rand_broj();
	int computer_move();
};
