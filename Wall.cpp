#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	color = { 0,0,0,0 };
	Size = 32;
	LoadBmp("Data/Wall.bmp");
}

AWall::AWall(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	LoadBmp("Data/Wall.bmp");
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	LoadBmp("Data/Wall.bmp");
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	LoadBmp("Data/Wall.bmp");
}

AWall::AWall(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color NewColor,Uint8 size)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
	color = NewColor;
	Size = size;
	LoadBmp("Data/Wall.bmp");
}


AWall::~AWall()
{
}

