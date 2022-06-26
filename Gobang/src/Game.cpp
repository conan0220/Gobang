#include <iostream>

#include "Game.h"
#include "Output.h"
#include "Math.h"

Game::Game()
	: ch_x(0), ch_y(0), GameMode(-1), is_game_end(false), turn(-1), round(0)
{
}

Game::~Game()
{
}

bool Game::InitializeGame()
{
	SelectGameMode();
	SelectWhoFirst();

	return true;
}

void Game::Loop()
{
	// Output the original checkerboard
	GenerateOutput();

	while (true)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();

		if (is_game_end)
		{
			break;
		}
	}
	
}

void Game::ShutdownSystem()
{
	exit(0);
}

Game Game::get()
{
	static Game instance;
	return instance;
}

void Game::SelectGameMode()
{
	while (true)
	{
		// output message
		Log::SelectGameMode();
		std::cin >> GameMode;
		if (GameMode == 0 || GameMode == 1)
		{
			break;
		}
		else
		{	
			err::InputWrongMode();
			continue;
		}
	}
	
}
void Game::SelectWhoFirst()
{
	turn = GetRandom(0, 1);
}

void Game::PrintWhosTurn()
{
	if (GameMode == 0)
	{
		switch (turn)
		{
		case 0:
		{
			Log::PlayerTurn();
			break;
		}
		case 1:
		{
			Log::ComputerTurn();
			break;
		}
		default:
		{
			err::OutOfRange();
			ShutdownSystem();
			break;
		}
		}
	}
	else if (GameMode == 1)
	{
		switch (turn)
		{
			case 0:
			{
				Log::PlayerOneTurn();
				break;
			}
			case 1:
			{
				Log::PlayerTwoTurn();
				break;
			}
			default:
			{
				err::OutOfRange();
				ShutdownSystem();
				break;
			}
		}
	}
}

void Game::ProcessInput()
{
	PrintWhosTurn();
	
	bool is_input_illegal = true;
	switch (GameMode)
	{
		case 0:		// PvE input
		{
			// PvE input
			break;
		}
		case 1:		// PvP input
		{
			while (is_input_illegal)
			{
				Log::InputChessPosition();
				PlayerInputChessPosition();
				is_input_illegal = (97 <= ch_x && ch_x <= 111 && 97 <= ch_y && ch_y <= 111) ? false : true;
				if (is_input_illegal)
				{
					err::OutOfRange();
				}
			}
			break;
		}
		default:
		{
			err::OutOfRange();
			ShutdownSystem();
			break;
		}
	}
	
	
	ConvertPosToDigitalPos();
	
}

void Game::UpdateGame()
{	
	// change turn to next one
	turn = (turn + 1) % 2;		
	// Update round
	round++;
	// Update chessboard 
	chess_board.self[chess_board.position.y][chess_board.position.x] = turn;

}

void Game::GenerateOutput()
{
	std::cout << std::endl;
	Log::ModifyColorOfMessage(7);
	std::cout << "Round: " << round << std::endl << std::endl;
	Log::ModifyColorOfMessage(0);
	chess_board.PrintOnScreen();
	std::cout << std::endl;
}

void Game::PlayerInputChessPosition()
{
	Log::ModifyColorOfMessage(5);
	std::cout << "x -> ";
	Log::ModifyColorOfMessage(0);
	std::cin >> ch_x;
	Log::ModifyColorOfMessage(5);
	std::cout << "y -> ";
	Log::ModifyColorOfMessage(0);
	std::cin >> ch_y;
}

void Game::ConvertPosToDigitalPos()
{
	chess_board.position.x = ch_x - 97;
	chess_board.position.y = ch_y - 97;
}

bool Game::PlayAgainOrNot()
{
	return false;
}

void Game::InitializeObjects()
{
}


