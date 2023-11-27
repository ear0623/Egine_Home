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
	Shape = 'M';
	SortOrder = 400;
	bCollide = false;
	srand((unsigned int)time(nullptr));
}

AMonster::AMonster(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
}

AMonster::AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
	SetCollide(NewbCollide);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	AActor::Tick();
	//random 4 direction,
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
