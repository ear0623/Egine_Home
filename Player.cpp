#include "Player.h"
#include "SimpleEngine.h"
#include "World.h"
#include "Goal.h"
#include "GameState.h"

APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	color = { 0,0,0,0 };
	Size = 32;
	LoadBmp("Data/Player.bmp", SDL_Color{ 255,0,255,0 });
	bIsSprite = true;
	SprintSizeX = 5;
	SprintSizeY = 5;
	SprintIndex=0;
	SprintDeirection=0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::APlayer(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	LoadBmp("Data/Player.bmp", SDL_Color{ 255,0,255,0 });
	bIsSprite = true;
	SprintSizeX = 5;
	SprintSizeY = 5;
	SprintIndex = 0;
	SprintDeirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	LoadBmp("Data/Player.bmp", SDL_Color{ 255,0,255,0 });
	bIsSprite = true;
	SprintSizeX = 5;
	SprintSizeY = 5;
	SprintIndex = 0;
	SprintDeirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	LoadBmp("Data/Player.bmp",SDL_Color{255,0,255,0});
	bIsSprite = true;
	SprintSizeX = 5;
	SprintSizeY = 5;
	SprintIndex = 0;
	SprintDeirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color NewColor, Uint8 size)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
	color = NewColor;
	Size = size;
	LoadBmp("Data/Player.bmp", SDL_Color{ 255,0,255,0 });
	bIsSprite = true;
	SprintSizeX = 5;
	SprintSizeY = 5;
	SprintIndex = 0;
	SprintDeirection = 0;
	ElaspedTime = 0;
	ProcessTime = 400;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();

	ElaspedTime += GENGINE->GetWorldDeltaSecons();
	if (ElaspedTime >= ProcessTime)
	{
		SprintIndex++;
		SprintIndex = SprintIndex % SprintSizeX;
		ElaspedTime = 0;

	}

	int KeyCode = GENGINE->MyEvent.key.keysym.sym;
	//KeyCode = MyEvent.key.keysym.sym;
	if (GENGINE->MyEvent.type == SDL_KEYDOWN)
	{
		return;
	}
	if (FSimpleEngine::GetGamestate()->IsGameOver)
	{
		return;
	}

	if (KeyCode ==SDLK_a)
	{
		if (!IsCollide(X - 1, Y))
		{
			SprintDeirection = 0;
			X--;
		}


	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{
			SprintDeirection = 1;
			X++;
		}
		
	}
	if (KeyCode==SDLK_s)
	{

		if (!IsCollide(X, Y + 1))
		{
			SprintDeirection = 3;
			Y++;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{
			SprintDeirection = 2;
			Y--;
		}

	}

	AGoal* MyGoal = nullptr;
	for (const auto& Actor : GENGINE->GetWorld()->GetAllactors())
	{
		MyGoal = dynamic_cast<AGoal*>(Actor);
		if (MyGoal && MyGoal->GetX() == X && MyGoal->GetY() == Y)
		{
			FSimpleEngine::GetGamestate()->IsNextLevel = true;
		}
	}
}

void APlayer::Render()
{
	__super::Render();
	
	//std::cout << Shape;
	
	
	int SprintWidth = MySurface->w / SprintSizeX;
	int SprintHeight = MySurface->h / SprintSizeY;
	int StartX = SprintIndex * SprintWidth;
	int StartY = SprintDeirection * SprintHeight;
	
	SDL_RenderCopy(GENGINE->MyRenderer, MyTexture, new SDL_Rect{ StartX,StartY,SprintWidth,SprintHeight }, new SDL_Rect{ X * Size,Y * Size,Size,Size });
	
}

bool APlayer::IsCollide(int NewX, int NewY)
{
	for (const auto& Actor : GENGINE->GetWorld()->GetAllactors())
	{
		if (this == Actor)
		{
			continue;
		}
		if (Actor->GetbCollide() == true && Actor->GetX() == NewX && Actor->GetY() == NewY)
		{
			return true;
		}
	}
	return false;
}
