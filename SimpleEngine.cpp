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

FSimpleEngine* FSimpleEngine::Instance = nullptr;

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
		int KeyCode = input();
		Tick(KeyCode);
		system("cls");
		Render();
	}
}

void FSimpleEngine::Stop()
{
	bIsRunning = false;
	delete World;
}

void FSimpleEngine::Term()
{

}

void FSimpleEngine::LoadLevel(std::string FileName)
{
	std::ifstream Mapfile(FileName);
	if (!Mapfile.is_open())
	{
		std::cout << "MapFile Is not Vaild" << std::endl;
		return;//return 1로 반환하고싶음
	}
	std::string Map[10];
	for (int Y = 0; Y < 10; ++Y)
	{
		std::getline(Mapfile, Map[Y]);
	}
	Mapfile.close();
	
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == '*')
			{
				GetWorld()->SpawnActor(new AWall(X, Y, '*', 100, true));
			}
			else if (Map[Y][X] == ' ')
			{
				//floor
			}
			else if (Map[Y][X] == 'P')
			{
				GetWorld()->SpawnActor(new APlayer(X, Y,'P',500));
			}
			else if (Map[Y][X] == 'M')
			{
				GetWorld()->SpawnActor(new AMonster(X, Y,'M',400));
				//fllor
			}
			else if (Map[Y][X] == 'G')
			{
				GetWorld()->SpawnActor(new AGoal(X, Y,'G',300,true));
				//floor
			}
			GetWorld()->SpawnActor(new AFloar(X, Y));
		}
	}

	GetWorld()->SortRenderOrder();

}

int FSimpleEngine::input()
{
	int keyCode = _getch();

	return keyCode;
}

void FSimpleEngine::Tick(int KeyCode)
{
	GetWorld()->Tick(KeyCode);
}

void FSimpleEngine::Render()
{
	GetWorld()->Render();
}

FSimpleEngine::FSimpleEngine()
{
	Init();
}
