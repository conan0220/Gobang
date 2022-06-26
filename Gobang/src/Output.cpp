#include <iostream>
#include <Windows.h>

#include "Output.h"

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
}

