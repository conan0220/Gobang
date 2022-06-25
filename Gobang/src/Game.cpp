#include <iostream>

#include "Game.h"
#include "Output.h"
#include "Math.h"

Game::Game()
	: GameMode(-1), is_game_end(false), turn(-1), round(0)
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
	if (GameMode == 0)
	{
		switch (turn)
		{
			case 0:
			{
				Log::PlayerFirst();
				break;
			}
			case 1:
			{
				Log::ComputerFirst();
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
				Log::PlayerOneFirst();
				break;
			}
			case 1:
			{
				Log::PlayerTwoFirst();
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

}

void Game::UpdateGame()
{
	round++;
}

void Game::GenerateOutput()
{
	std::cout << std::endl;
	Log::ModifyColorOfMessage(7);
	std::cout << "Round: " << round << std::endl;
	Log::ModifyColorOfMessage(0);
	chess_board.PrintOnScreen();
}

bool Game::PlayAgainOrNot()
{
	return false;
}

void Game::InitializeObjects()
{
}
