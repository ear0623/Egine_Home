#include "Actor.h"
#include <Windows.h>
#include <Iostream>

AActor::AActor() : X(0), Y(0), Shape(' '), SortOrder(0), bCollide(false)
{
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
}

AActor::AActor(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
}

AActor::~AActor()
{
}

void AActor::BeginePlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;
}
