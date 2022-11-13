#pragma once

#include "Coordinate.h"

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();

	// Initialize data
	void InitializeData();
	// Output chessboard on the scteen
	void Render();
	void Update(const int& turn);
	// Get Info self
	void GetInfoSelf();

	// ChessBoard's width
	const int width;
	// ChessBoard's height
	const int height;
	// Position of Chessboard
	Position position;
	// ChessBoard |  player, player1 -> -1 | computer, player2 -> 1 | NULL -> 0
	int self[15][15];
private:
	
};