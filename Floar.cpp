#include "Floar.h"

AFloar::AFloar()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
}

AFloar::AFloar(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AFloar::AFloar(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AFloar::AFloar(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
}

AFloar::AFloar(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
	bCollide = NewbCollide;
}

AFloar::~AFloar()
{
}