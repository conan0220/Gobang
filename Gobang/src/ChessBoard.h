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
	void PrintOnScreen();

	// Position of Checkerboard
	Position position;
	// ChessBoard 
	int self[15][15];
private:
	
	
	
	// ChessBoard's width
	const int width;
	// ChessBoard's height
	const int height;
	
	
};