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
	void PlayerFirst();
	// Output Computer first
	void ComputerFirst();
	// Output Player1 first
	void PlayerOneFirst();
	// Output Player2 first
	void PlayerTwoFirst();
	
}