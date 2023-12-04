#include "Player.h"
#include "SimpleEngine.h"
#include "World.h"
#include "Goal.h"
#include "GameState.h"

APlayer::APlayer()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	SortOrder = 500;
	bCollide = false;
}

APlayer::APlayer(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
}

APlayer::APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();
	int KeyCode = FSimpleEngine::KeyCode;
	if (FSimpleEngine::GetGamestate()->IsGameOver)
	{
		return;
	}

	if (KeyCode ==SDLK_a)
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}


	}
	if (KeyCode == SDLK_d)
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}
		
	}
	if (KeyCode==SDLK_s)
	{

		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == SDLK_w)
	{
		if (!IsCollide(X, Y - 1))
		{
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
