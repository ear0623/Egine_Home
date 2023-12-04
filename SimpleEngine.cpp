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
#include <iostream>
#include <fstream>

FSimpleEngine* FSimpleEngine::Instance = nullptr;
int FSimpleEngine::KeyCode = 0;

FSimpleEngine::~FSimpleEngine()
{
	Term();
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();


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
		SDL_PollEvent(&MyEvent);
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
	int Y = 0;
	std::string line;
	std::ifstream file(FileName); // example.txt 파일을 연다. 없으면 생성. 
	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int X = 0; X < line.length(); X++)
			{
				LoadActor(X,Y , line[X]);
			}
			Y++;
		}
		file.close(); // 열었떤 파일을 닫는다. 
	}
	else 
	{
		Stop();
	}
	
	GetWorld()->SortRenderOrder();

	GameMode = new AGameMode();
	GetWorld()->SpawnActor(GameMode);
	GameState = new AGameState();
	GetWorld()->SpawnActor(GameState);
}

void FSimpleEngine::input()
{
	KeyCode = MyEvent.key.keysym.sym;
}

void FSimpleEngine::Tick()
{
	GetWorld()->Tick();
}

void FSimpleEngine::Render()
{
	GetWorld()->Render();
}

void FSimpleEngine::LoadActor(int NewX, int NewY, char Actor)
{
	if (Actor == '*')
	{
		GetWorld()->SpawnActor(new AWall(NewX, NewY, '*', 100, true));
	}
	else if (Actor == ' ')
	{
		GetWorld()->SpawnActor(new AFloar(NewX, NewY, ' ', 0, false));
		//floor
	}
	else if (Actor == 'P')
	{
		GetWorld()->SpawnActor(new APlayer(NewX, NewY, 'P', 500, false));
	}
	else if (Actor == 'M')
	{
		GetWorld()->SpawnActor(new AMonster(NewX, NewY, 'M', 400, false));
		//fllor
	}
	else if (Actor == 'G')
	{
		GetWorld()->SpawnActor(new AGoal(NewX, NewY, 'G', 300, false));
		//floor
	}
}

FSimpleEngine::FSimpleEngine()
{
	GameMode = nullptr;
	GameState = nullptr;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	MyWindow = SDL_CreateWindow("Hellow World", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	Init();
}
