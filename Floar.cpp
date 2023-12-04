#include "Floar.h"

AFloar::AFloar()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	SortOrder = 0;
	bCollide = false;
	color = { 0,0,0,0 };
	Size = 32;
	LoadBmp("Data/Coin.bmp");
	
}

AFloar::AFloar(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	LoadBmp("Data/floor.bmp");
}

AFloar::AFloar(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	LoadBmp("Data/floor.bmp");
}

AFloar::AFloar(int NewX, int NewY, char NewShape, int NewSortOrder)//알아서 생략되니까 지금처럼 다 적을 필요 없음
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SortOrder = NewSortOrder;
	LoadBmp("Data/floor.bmp");
}

AFloar::AFloar(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color NewColor, Uint8 size)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
	color = NewColor;
	Size = size;
	LoadBmp("Data/floor.bmp");
}

AFloar::~AFloar()
{
}