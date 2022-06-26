#pragma once

namespace err
{
	// Output "Error"
	void Error();
	// Output "Failure to initialize the game"
	void FailureToInitializeGame();
	// Output "Input the wrong mode"
	void InputWrongMode();
	// Output "Out of range"
	void OutOfRange();
}

namespace Log
{
	// Output select game mode message
	void SelectGameMode();
	// Output modify the color of message | 0->white 1->gray 2->red 3->green 4->blue 5->yellow 6->pink 7->cyan-blue
	void ModifyColorOfMessage(const int& color);
	// Output Player first
	void PlayerTurn();
	// Output Computer first
	void ComputerTurn();
	// Output Player1 first
	void PlayerOneTurn();
	// Output Player2 first
	void PlayerTwoTurn();
	// Output message of Input chess position
	void InputChessPosition();
	
}