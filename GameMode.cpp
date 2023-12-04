#include "GameMode.h"
#include "Player.h"
#include "Goal.h"
#include "SimpleEngine.h"
#include "World.h"
#include <iostream>
#include "GameState.h"


AGameMode::AGameMode()
{
	SortOrder = 0;
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor::Tick();
	
	if (FSimpleEngine::GetGamestate()->IsNextLevel)
	{
		std::cout << "Complete" << std::endl;
		//GENGINE->Stop();
		GENGINE->LoadLevel("Data/Level02.smap");
	}
	if (FSimpleEngine::GetGamestate()->IsGameOver)
	{
		std::cout << "GameOver" << std::endl;
		GENGINE->Stop();
	}
}

void AGameMode::Render()
{
}
