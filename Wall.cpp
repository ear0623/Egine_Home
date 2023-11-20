#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	SortOrder = 200;
	bCollide = false;
}

AWall::AWall(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
}

AWall::~AWall()
{
}

