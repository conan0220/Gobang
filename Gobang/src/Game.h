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

	static Game get();


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
	// Play again or not
	bool PlayAgainOrNot();
	// Initialize Player1 Player2 or Player Computer when press play again
	void InitializeObjects();

	// Establish CheckerBoard object
	ChessBoard chess_board;
	// Establish Computer and Player objects
	Player p;
	Computer cp;
	// Establish two Player objects
	Player p1;
	Player p2;

	// Game mode PvE is 0 PvP is 1
	int GameMode;
	// Game end or not
	bool is_game_end;
	// who's turn
	int turn;
	// Which round 
	int round;
};