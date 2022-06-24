#include "Game.h"
#include "Output.h"

Game::Game()
	: GameMode(-1)
{
}

Game::~Game()
{
}

bool Game::InitializeGame()
{
	// �ЫشѽL

	// output message
	Log::SelectGameMode();	
	SelectGameMode();

	return true;
}

void Game::Loop()
{
}

void Game::EndGame()
{
}

void Game::ShutdownSystem()
{
}

void Game::SelectGameMode()
{

}

void Game::ProcessInput()
{
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
}
