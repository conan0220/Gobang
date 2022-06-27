#include <iostream>
#include <Windows.h>

#include "Output.h"
#include "Game.h"

namespace err 
{
	void Error()
	{
		Log::ModifyColorOfMessage(2);
		std::cout << "[Error] ";
		Log::ModifyColorOfMessage(0);
	}
	void FailureToInitializeGame()
	{
		err::Error();
		Log::ModifyColorOfMessage(1);
		std::cout << "Failure to initialize the game" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void InputWrongMode()
	{
		err::Error();
		Log::ModifyColorOfMessage(1);
		std::cout << "Input the wrong mode" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void OutOfRange()
	{
		err::Error();
		Log::ModifyColorOfMessage(1);
		std::cout << "Out of range" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void FailureToInput()
	{
		err::Error();
		Log::ModifyColorOfMessage(1);
		std::cout << "Failure to input" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
}

namespace Log
{
	void SelectGameMode()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Select game mode (PvE->0 PvP->1): ";
		Log::ModifyColorOfMessage(0);
	}
	void ModifyColorOfMessage(const int& color)
	{
		switch (color)
		{
			case 0:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
			case 1:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				break;
			}
			case 2:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				break;
			}
			case 3:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				break;
			}
			case 4:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
				break;
			}
			case 5:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			}
			case 6:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
				break;
			}
			case 7:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
			default:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}

		}
	}
	void PlayerTurn()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player's turn" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void ComputerTurn()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Computer's turn" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void PlayerOneTurn()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player1's turn" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void PlayerTwoTurn()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player2's turn" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void InputChessPosition()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Input Chess Position(x, y):" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void WhosTurn(const int& GameMode, const int& turn)
	{
		if (GameMode == 0)
		{
			switch (turn)
			{
				case -1:
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
					Game::get().ShutdownSystem();
					break;
				}
			}
		}
		else if (GameMode == 1)
		{
			switch (turn)
			{
				case -1:
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
					Game::get().ShutdownSystem();
					break;
				}
			}
		}
	}
	void PlayerOneWin()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player1 win" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void PlayerTwoWin()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player2 win" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void PlayerWin()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Player win" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
	void ComputerWin()
	{
		Log::ModifyColorOfMessage(5);
		std::cout << "Computer win" << std::endl;
		Log::ModifyColorOfMessage(0);
	}
}

