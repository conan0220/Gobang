#pragma once

#include "Output.h"
#include "ChessBoard.h"
#include "Player.h"
#include "Computer.h"

class Game
{
public:
	Game();
	~Game();

	// Initialize the game such as establish the objects
	bool InitializeGame();
	// Run the game
	void Loop();
	// Shutdown entire game
	void ShutdownSystem();

	static Game& get();

	// who's turn | player, player1 -> -1 | computer, player2 -> 1
	int turn;
	// How many chess can make a line
	int target = 5;
private:
	// Select PvE->0 or PvP->1
	void SelectGameMode();
	// Select who first
	void SelectWhoFirst();
	

	// Deal with the input event
	void ProcessInput();
	// Update the game
	void UpdateGame();
	// Display output on the screen
	void GenerateOutput();
	// Is someone win or not
	bool GameEndOrNot();
	// Is chess connected in a line
	bool IsItConnectedInLine(const ChessBoard& chess_board, const int& turn);
	// Is connected in virtical
	bool IsConnectedInVirtical(const ChessBoard& chess_board, const int& turn, const int& target);
	// Is connected in horizontal
	bool IsConnectedInHorizontal(const ChessBoard& chess_board, const int& turn, const int& target);
	// Is connected in slope 1
	bool IsConnectedInSlopeOne(const ChessBoard& chess_board, const int& turn, const int& target);
	// Is connected in slope -1
	bool IsConnectedInSlopeMinusOne(const ChessBoard& chess_board, const int& turn, const int& target);

	// Establish CheckerBoard object
	ChessBoard chess_board;
	// Establish Computer and Player objects
	Player p;
	Computer cp;
	Computer cp1;
	// Establish two Player objects
	Player p1;
	Player p2;

	// Game mode PvE is 0 PvP is 1
	int GameMode;
	// Game end or not
	bool is_game_end;
	
	// Which round 
	int round;
	
};
