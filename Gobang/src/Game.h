#pragma once

class Game
{
public:
	Game();
	~Game();

	// Initialize the game
	bool InitializeGame();
	// Run the game
	void Loop();
	// Game over, chose initializeGame() or ShutdownSystem() 
	void EndGame();
	// Shutdown entire game
	void ShutdownSystem();


private:
	// Select PvE or PvP
	void SelectGameMode();

	// Deal with the input event
	void ProcessInput();
	// Update the game
	void UpdateGame();
	// Display output on the screen
	void GenerateOutput();

	// Game mode PvE is 0 PvP is 1
	int GameMode;


};