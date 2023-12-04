#include "Monster.h"
#include "SimpleEngine.h"
#include "World.h"
#include "Player.h"
#include "GameState.h"
#include <iostream>


AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	color = { 0,0,0,0 };
	Size = 32;
	srand((unsigned int)time(nullptr));
	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBmp("Data/Slime.bmp");
}

AMonster::AMonster(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBmp("Data/Slime.bmp");
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBmp("Data/Slime.bmp");
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBmp("Data/Slime.bmp");
}


AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color NewColor, Uint8 size)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
	color = NewColor;
	Size = size;
	ProcessTime = 500;
	ElaspedTime = 0;
	LoadBmp("Data/Slime.bmp");
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	AActor::Tick();
	//random 4 direction,
	ElaspedTime += GENGINE->GetWorldDeltaSecons();
	if (ElaspedTime <= ProcessTime)
	{
		return;
	}
	else
	{
		ElaspedTime = 0;
	}

	for (const auto& Actor : GENGINE->GetWorld()->GetAllactors())
	{
		APlayer* MyPlayer = dynamic_cast<APlayer*>(Actor);
		if (MyPlayer &&
			MyPlayer->GetX() == X &&
			MyPlayer->GetY() == Y)
		{
			FSimpleEngine::GetGamestate()->IsGameOver = true;
			return;
		}
	}

	int Direction = rand() % 4;

	if (Direction ==(int)EMonsterDirection::Left)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}
	}
	if (Direction == (int)EMonsterDirection::Right)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
	}
	if (Direction == (int)EMonsterDirection::Down)
	{
		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (Direction == (int)EMonsterDirection::Up)
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}
	}
}
bool AMonster::IsCollide(int NewX, int NewY)
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
