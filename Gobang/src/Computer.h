#pragma once

#include "Coordinate.h"
#include "ChessBoard.h"

class Computer
{
public:
	Computer();
	~Computer();

	void Input(ChessBoard& chess_board, const int& target, const int& turn);
	// The position computer select
	void SelectChessPosition(ChessBoard& chess_board, const int& target, const int& turn);
	// Analyze where is the best position
	int AI_1(ChessBoard& chess_board, const int& target, int x, int y, int xp, const int& turn);

	int XpOfVertical(const ChessBoard& chess_board, const int& x, const int& y, const int& turn);
	int XpOfHorizontal(const ChessBoard& chess_board, const int& x, const int& y, const int& turn);
	int XpOfSlopeOne(const ChessBoard& chess_board, const int& x, const int& y, const int& turn);
	int XpOfSlopeMinusOne(const ChessBoard& chess_board, const int& x, const int& y, const int& turn);
private:

	// Position of Computer's chessman
	Position position;
};