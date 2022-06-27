#pragma once

#include "Coordinate.h"
#include "ChessBoard.h"

class Player
{
public:
	Player();
	~Player();

	void Input(ChessBoard& chess_board);

	void GetInfo();

private:
	// Convert position to real dgital position
	void ConvertPosToDigitalPos(char& ch_x, char& ch_y);

	// Position of Player's chessman
	Position position;
};
