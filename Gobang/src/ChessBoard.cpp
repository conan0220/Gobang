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
			self[i][j] = -1;
		}
	}
}

void ChessBoard::PrintOnScreen()
{
	char temp = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			switch (self[i][j])
			{
				case -1:
				{
					temp = '.';
					break;
				}	
				case 0:
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
