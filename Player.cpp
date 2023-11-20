#include "Player.h"
#include "SimpleEngine.h"
#include "World.h"

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

void APlayer::Tick(int KeyCode)
{
	__super::Tick(KeyCode);

	if (KeyCode == 'A' || KeyCode == 'a')
	{
		if (!IsCollide(X - 1, Y))
		{
			X--;
		}

	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		if (!IsCollide(X + 1, Y))
		{
			X++;
		}

	}
	if (KeyCode == 'S' || KeyCode == 's')
	{

		if (!IsCollide(X, Y + 1))
		{
			Y++;
		}
	}
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		if (!IsCollide(X, Y - 1))
		{
			Y--;
		}

	}
	else
	{

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
