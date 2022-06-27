#include <iostream>

#include "Player.h"
#include "Output.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Input(ChessBoard& chess_board)
{
	char ch_x, ch_y;

	bool is_input_illegal = true;
	while (is_input_illegal)
	{
		
		Log::ModifyColorOfMessage(5);
		std::cout << "x -> ";
		Log::ModifyColorOfMessage(0);
		std::cin >> ch_x;
		Log::ModifyColorOfMessage(5);
		std::cout << "y -> ";
		Log::ModifyColorOfMessage(0);
		std::cin >> ch_y;
		ConvertPosToDigitalPos(ch_x, ch_y);
		is_input_illegal = (97 <= ch_x && ch_x <= 111 && 97 <= ch_y && ch_y <= 111) && (chess_board.self[position.y][position.x] == 0) ? false : true;
		if (is_input_illegal)
		{
			err::FailureToInput();
		}
	}

	chess_board.position.x = position.x;
	chess_board.position.y = position.y;
}

void Player::ConvertPosToDigitalPos(char& ch_x, char& ch_y)
{
	position.x = ch_x - 97;
	position.y = ch_y - 97;
}

void Player::GetInfo()
{
	std::cout << "x: " << position.x << std::endl;
	std::cout << "y: " << position.y << std::endl;
}