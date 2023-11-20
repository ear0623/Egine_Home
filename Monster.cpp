#include "Monster.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = 'M';
	SortOrder = 400;
	bCollide = false;
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
	SortOrder = NewSortOrder;
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
