#pragma once

namespace err
{
	// Output "Error"
	void Error();
	// Output "Failure to initialize the game"
	void FailureToInitializeGame();
}

namespace Log
{
	// Output select game mode message
	void SelectGameMode();
	// Modify the color of message | 0->white 1->gray 2->red 3->green 4->blue 5->yellow 6->pink 7->cyan-blue
	void ModifyColorOfMessage(const int& color);
	
}