
#include "Game.h"
#include "Output.h"


int main()
{
	Game gobang;
	bool is_success = gobang.InitializeGame();

	if (is_success)
	{
		gobang.Loop();
	}
	else
	{
		err::FailureToInitializeGame();
	}
	gobang.ShutdownSystem();
}