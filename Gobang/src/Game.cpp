#include <iostream>
#include <Windows.h>

#include "Game.h"
#include "Output.h"
#include "Math.h"


Game::Game()
	: GameMode(-1), is_game_end(false), turn(0), round(0)
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
	// Output the original chessboard
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

Game& Game::get()
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
	if (turn == 0)
	{
		turn = -1;
	}
	
}

void Game::ProcessInput()
{
	Log::WhosTurn(GameMode, turn);
	
	Log::InputChessPosition();
	switch (GameMode)
	{
		case 0:		// PvE input
		{
			if (turn == -1)
			{
				p.Input(chess_board);
			}
			else if (turn == 1)
			{
				cp.Input(chess_board, target, turn);
			}

			break;
		}
		case 1:		// PvP input
		{	
			if (turn == -1)			// p1 turn
			{
				p1.Input(chess_board);
			}
			else if (turn == 1)		// p2 turn
			{
				p2.Input(chess_board);
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

	
	
}

void Game::UpdateGame()
{	
	// Chessboard update
	chess_board.Update(turn);
	// Is someone win or not
	is_game_end = GameEndOrNot();

	// change turn to next one
	turn *= -1;
	// Update round
	round++;
}

void Game::GenerateOutput()
{
	std::cout << std::endl;
	Log::ModifyColorOfMessage(7);
	std::cout << "Round: " << round << std::endl << std::endl;
	Log::ModifyColorOfMessage(0);
	chess_board.Render();
	std::cout << std::endl;
	
	if (is_game_end)
	{
		turn *= -1;		// reverse turn to the winner 
		switch (GameMode)
		{
			case 0:		// PvE mode
			{
				if (turn == -1)
				{
					Log::PlayerWin();
				}
				else if (turn == 1)
				{
					Log::ComputerWin();
				}
				break;
			}
			case 1:
			{
				if (turn == -1)
				{
					Log::PlayerOneWin();
				}
				else if (turn == 1)
				{
					Log::PlayerTwoWin();
				}
				break;
			}

		}
	}
}

bool Game::GameEndOrNot()
{
	if (IsItConnectedInLine(chess_board, turn))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::IsItConnectedInLine(const ChessBoard& chess_board, const int& turn)
{
	

	if (IsConnectedInVirtical(chess_board, turn, target))
	{
		return true;
	}
	else if (IsConnectedInHorizontal(chess_board, turn, target))
	{
		return true;
	}
	else if (IsConnectedInSlopeOne(chess_board, turn, target))
	{
		return true;
	}
	else if (IsConnectedInSlopeMinusOne(chess_board, turn, target))
	{
		return true;
	}
		
	return false;
}

bool Game::IsConnectedInVirtical(const ChessBoard& chess_board, const int& turn, const int& target)
{
	int x = chess_board.position.x;
	int y = chess_board.position.y;
	int total = 0;						// total number of a line of chess

	// vertical
	while (chess_board.self[y][x] == turn && y >= 0)
	{
		total += 1;
		y -= 1;

		if (total >= 5)
		{
			break;
		}
	}
	x = chess_board.position.x;
	y = chess_board.position.y + 1;
	while (chess_board.self[y][x] == turn && y < chess_board.height)
	{
		total += 1;
		y += 1;

		if (total >= 5)
		{
			break;
		}
	}
	if (total >= target)
	{
		return true;
	}

	return false;
}

bool Game::IsConnectedInHorizontal(const ChessBoard& chess_board, const int& turn, const int& target)
{
	int x = chess_board.position.x;
	int y = chess_board.position.y;
	int total = 0;						// total number of a line of chess

	// horizontal
	while (chess_board.self[y][x] == turn && x < chess_board.width)
	{
		total += 1;
		x += 1;

		if (total >= 5)
		{
			break;
		}
	}
	x = chess_board.position.x - 1;
	y = chess_board.position.y;
	while (chess_board.self[y][x] == turn && x >= 0)
	{
		total += 1;
		x -= 1;

		if (total >= 5)
		{
			break;
		}
	}
	if (total >= target)
	{
		return true;
	}

	return false;
}

bool Game::IsConnectedInSlopeOne(const ChessBoard& chess_board, const int& turn, const int& target)
{
	int x = chess_board.position.x;
	int y = chess_board.position.y;
	int total = 0;						// total number of a line of chess

	// slope == 1
	while (chess_board.self[y][x] == turn && x < chess_board.width && y >= 0)
	{
		total += 1;
		x += 1;
		y -= 1;

		if (total >= 5)
		{
			break;
		}
	}
	x = chess_board.position.x - 1;
	y = chess_board.position.y + 1;
	while (chess_board.self[y][x] == turn && x >= 0 && y < chess_board.height)
	{
		total += 1;
		x -= 1;
		y += 1;

		if (total >= 5)
		{
			break;
		}
	}
	if (total >= target)
	{
		return true;
	}

	return false;
}

bool Game::IsConnectedInSlopeMinusOne(const ChessBoard& chess_board, const int& turn, const int& target)
{
	int x = chess_board.position.x;
	int y = chess_board.position.y;
	int total = 0;						// total number of a line of chess

	// slope == -1
	while (chess_board.self[y][x] == turn && x < chess_board.width && y < chess_board.height)
	{
		total += 1;
		x += 1;
		y += 1;

		if (total >= 5)
		{
			break;
		}
	}
	x = chess_board.position.x - 1;
	y = chess_board.position.y - 1;
	while (chess_board.self[y][x] == turn && x >= 0 && y >= 0)
	{
		total += 1;
		x -= 1;
		y -= 1;

		if (total >= 5)
		{
			break;
		}
	}
	if (total >= target)
	{
		return true;
	}

	return false;
}


