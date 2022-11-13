#include <iostream>

#include "Computer.h"
#include "Output.h"
#include "Game.h"
#include "Math.h"

Computer::Computer()
{
}

Computer::~Computer()
{
}

void Computer::Input(ChessBoard& chess_board, const int& target, const int& turn)
{
	SelectChessPosition(chess_board, target, turn);

	Log::ModifyColorOfMessage(5);
	std::cout << "x -> ";
	Log::ModifyColorOfMessage(0);
	std::cout << (char)(position.x + 97) << std::endl;
	Log::ModifyColorOfMessage(5);
	std::cout << "y -> ";
	Log::ModifyColorOfMessage(0);
	std::cout << (char)(position.y + 97) << std::endl;

	chess_board.position.x = position.x;
	chess_board.position.y = position.y;
}

void Computer::SelectChessPosition(ChessBoard& chess_board, const int& target, const int& turn)
{
	AI_1(chess_board, target, 0, 0, 4 * target, turn);
}

int Computer::AI_1(ChessBoard& chess_board, const int& target, int x, int y, int xp, const int& turn)
{
	int temp_xp = target;
	int temp;

	temp_xp > (temp = XpOfVertical(chess_board, x, y, turn)) ? (temp_xp = temp) : 0 ;
	temp_xp > (temp = XpOfHorizontal(chess_board, x, y, turn)) ? (temp_xp = temp) : 0;
	temp_xp > (temp = XpOfSlopeOne(chess_board, x, y, turn)) ? (temp_xp = temp) : 0;
	temp_xp > (temp = XpOfSlopeMinusOne(chess_board, x, y, turn)) ? (temp_xp = temp) : 0;
	

	// Find the best new position
	if (temp_xp < xp && chess_board.self[y][x] == 0)
	{
		xp = temp_xp;
		position.x = x;
		position.y = y;
	}
	//else if (temp_xp = xp)		// change the position avoid repeating the smae place
	//{
	//	switch (GetRandom(0, 1))
	//	{
	//		case 0:
	//		{
	//			xp = temp_xp;
	//			position.x = x;
	//			position.y = y;
	//			break;
	//		}
	//		case 1:
	//		{
	//			break;
	//		}
	//	}
	//}

	// Is recursive end?
	if (xp <= 0)
	{
		//std::cout << "x:" << x << " y:" << y << " xp:" << temp_xp << std::endl;
		// end
		return 0;
	}
	else if (x + 1 < chess_board.width)
	{
		x++;
	}
	else if (y + 1 < chess_board.height)
	{
		y++;
		x = 0;
	}
	else
	{
		//std::cout << "x:" << x << " y:" << y << " xp:" << temp_xp << std::endl;
		// end
		return 0;
	}
	
	//std::cout << "x:" << x << " y:" <<  y << " xp:" << temp_xp << std::endl;
	
	// Next recursive
	AI_1(chess_board, target, x, y, xp, turn);

	return 0;
}

int Computer::XpOfVertical(const ChessBoard& chess_board, const int& x, const int& y, const int& turn)
{
	int temp_x = x;
	int temp_y = y;
	int xp = Game::get().target;						// total number of a line of chess

	// vertical
	temp_y -= 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_y >= 0) // 1 is computer's chess symbol
	{
		xp -= 1;
		temp_y -= 1;

		if (xp <= 1)
		{
			return xp;
		}
	}
	temp_x = x;
	temp_y = y + 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_y < chess_board.height)
	{
		xp -= 1;
		temp_y += 1;

		if (xp <= 1)
		{
			return xp;
		}
	}

	return xp;
}

int Computer::XpOfHorizontal(const ChessBoard& chess_board, const int& x, const int& y, const int& turn)
{
	int temp_x = x;
	int temp_y = y;
	int xp = Game::get().target;						// total number of a line of chess

	// horizontal
	temp_x += 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x < chess_board.width) // 1 is computer's chess symbol
	{
		xp -= 1;
		temp_x += 1;

		if (xp <= 1)
		{
			return xp;
		}
	}
	temp_x = x - 1;
	temp_y = y;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x >= 0)
	{
		xp -= 1;
		temp_x -= 1;

		if (xp <= 1)
		{
			return xp;
		}
	}

	return xp;
}

int Computer::XpOfSlopeOne(const ChessBoard& chess_board, const int& x, const int& y, const int& turn)
{
	int temp_x = x;
	int temp_y = y;
	int xp = Game::get().target;						// total number of a line of chess

	// slope one
	temp_x += 1;
	temp_y -= 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x < chess_board.width && temp_y >= 0) // 1 is computer's chess symbol
	{
		xp -= 1;
		temp_x += 1;
		temp_y -= 1;

		if (xp <= 1)
		{
			return xp;
		}
	}
	temp_x = x - 1;
	temp_y = y + 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x >= 0 && temp_y < chess_board.height)
	{
		xp -= 1;
		temp_x -= 1;
		temp_y += 1;

		if (xp <= 1)
		{
			return xp;
		}
	}

	return xp;
}

int Computer::XpOfSlopeMinusOne(const ChessBoard& chess_board, const int& x, const int& y, const int& turn)
{
	int temp_x = x;
	int temp_y = y;
	int xp = Game::get().target;						// total number of a line of chess

	// slope minus one
	temp_x -= 1;
	temp_y -= 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x >= 0 && temp_y >= 0) // 1 is computer's chess symbol
	{
		xp -= 1;
		temp_x -= 1;
		temp_y -= 1;

		if (xp <= 1)
		{
			return xp;
		}
	}
	temp_x = x + 1;
	temp_y = y + 1;
	while (chess_board.self[temp_y][temp_x] == turn && temp_x < chess_board.width && temp_y < chess_board.height)
	{
		xp -= 1;
		temp_x += 1;
		temp_y += 1;

		if (xp <= 1)
		{
			return xp;
		}
	}

	return xp;
}
