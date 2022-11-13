#include <iostream>

#include "ChessBoard.h"
#include "Output.h"
#include "Game.h"
#include "Output.h"

ChessBoard::ChessBoard()
	: width(15), height(15)
{
	InitializeData();
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::InitializeData()
{
	position.x = 0;
	position.y = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			self[i][j] = 0;
		}
	}
}

void ChessBoard::Render()
{
	char row = 97;		// row name | 97 is ascii code
	char column = 97;	// column name | 97 is ascii code
	char temp = 0;

	Log::ModifyColorOfMessage(3);
	std::cout << " ";
	for (int i = 0; i < width; i++)
	{
		std::cout << " " << column ;
		column++;
	}
	Log::ModifyColorOfMessage(0);

	std::cout << std::endl;
	for (int i = 0; i < height; i++)
	{
		Log::ModifyColorOfMessage(3);
		std::cout << row << " ";
		row++;
		Log::ModifyColorOfMessage(0);

		for (int j = 0; j < width; j++)
		{
			switch (self[i][j])
			{
				case 0:
				{
					temp = '.';
					break;
				}	
				case -1:
				{
					temp = 'o';
					Log::ModifyColorOfMessage(2);
					break;
				}	
				case 1:
				{
					temp = 'o';
					Log::ModifyColorOfMessage(5);
					break;
				}
				default:
				{
					err::OutOfRange();
					Game::get().ShutdownSystem();
					break;
				}
			}
			std::cout << temp << " ";
			Log::ModifyColorOfMessage(0);
		}
		std::cout << std::endl;
	}
	Log::ModifyColorOfMessage(0);
}

void ChessBoard::Update(const int& turn)
{
	// Update chessboard 
	self[position.y][position.x] = turn;
}

void ChessBoard::GetInfoSelf()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << self[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
