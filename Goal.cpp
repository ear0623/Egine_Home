#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	SortOrder = 300;
	bCollide = false;
}

AGoal::AGoal(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AGoal::AGoal(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
}

AGoal::AGoal(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
}

AGoal::~AGoal()
{
}
