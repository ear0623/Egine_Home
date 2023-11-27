#include "SimpleEngine.h"
#include "conio.h"
#include "World.h"
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include "Floar.h"
#include "Monster.h"
#include <fstream>
#include <iostream>
#include "GameMode.h"
#include "GameState.h"

FSimpleEngine* FSimpleEngine::Instance = nullptr;
int FSimpleEngine::KeyCode = 0;

FSimpleEngine::~FSimpleEngine()
{
	Term();
}

void FSimpleEngine::Init()
{
	
	bIsRunning = true;
	World = new UWorld();
}

void FSimpleEngine::Run()
{
	while (bIsRunning)
	{
		input();
		Tick();
		system("cls");
		Render();
	}
}

void FSimpleEngine::Stop()
{
	bIsRunning = false;
	
}

void FSimpleEngine::Term()
{
	GameMode = nullptr;
	delete World;
	GameState = nullptr;
	bIsRunning = false;
}

void FSimpleEngine::LoadLevel(std::string FileName)
{
	
	std::string Map[10] = {
			"****************",
			"*P				*",
			"*				*",
			"*				*",
			"*     M		*",
			"*				*",
			"*				*",
			"*       G		*",
			"* M			*",
			"****************"
	};
	
	
	
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < Map[Y].length(); ++X)
		{
			if (Map[Y][X] == '*')
			{
				GetWorld()->SpawnActor(new AWall(X, Y, '*', 100, true));
			}
			else if (Map[Y][X] == ' ')
			{
				GetWorld()->SpawnActor(new AFloar(X, Y, ' ', 0, false));
				//floor
			}
			else if (Map[Y][X] == 'P')
			{
				GetWorld()->SpawnActor(new APlayer(X, Y,'P',500, false));
			}
			else if (Map[Y][X] == 'M')
			{
				GetWorld()->SpawnActor(new AMonster(X, Y,'M',400,false));
				//fllor
			}
			else if (Map[Y][X] == 'G')
			{
				GetWorld()->SpawnActor(new AGoal(X, Y,'G',300,false));
				//floor
			}
		}
	}
	GetWorld()->SortRenderOrder();

	GameMode = new AGameMode();
	GetWorld()->SpawnActor(GameMode);
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameState);
}

void FSimpleEngine::input()
{
	KeyCode = _getch();
}

void FSimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void FSimpleEngine::Render()
{
	GetWorld()->Render();
}

FSimpleEngine::FSimpleEngine()
{
	GameMode = nullptr;
	GameState = nullptr;
	Init();
}
