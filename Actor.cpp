#include "Actor.h"
#include <Windows.h>
#include <Iostream>
#include "SimpleEngine.h"

AActor::AActor() : X(0), Y(0), Shape(' '), SortOrder(0), bCollide(false), color{ 0,0,0,0 }, Size(32)
{
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SprintSizeX = 1;
	SprintSizeY = 1;
	animation = 0;
	
	
}

AActor::AActor(int NewX, int NewY)
{
	SetX(NewX);
	SetY(NewY);
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SprintSizeX = 1;
	SprintSizeY = 1;
	animation = 0;
}

AActor::AActor(int NewX, int NewY, char NewShape)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SprintSizeX = 1;
	SprintSizeY = 1;
	animation = 0;
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewSortOrder)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SprintSizeX = 1;
	SprintSizeY = 1;
	animation = 0;
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide,SDL_Color NewColor, Uint8 size)
{
	SetX(NewX);
	SetY(NewY);
	Shape = NewShape;
	SetSortOrder(NewSortOrder);
	SetCollide(NewbCollide);
	color = NewColor;
	Size=size;
	MySurface = nullptr;
	MyTexture = nullptr;
	bIsSprite = false;
	SprintSizeX = 1;
	SprintSizeY = 1;
	animation = 0;
}

AActor::~AActor()
{
	SDL_FreeSurface(MySurface);
	SDL_DestroyTexture(MyTexture);
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

	//메모리 -> gpu순
	std::cout << Shape;
	//SDL_Rect myrect{ 1,1,5,5 };
	//SDL_SetRenderDrawColor(GENGINE->MyRenderer, color.r, color.g, color.b, color.a);
	//int Rect = SDL_RenderDrawRect(GENGINE->MyRenderer, &myrect);

	//SDL_RenderDrawPoint(GENGINE->MyRenderer, (X), (Y));
	//SDL_RenderFillRect(GENGINE->MyRenderer, new SDL_Rect{ X*Size,Y*Size,Size,Size });
	//vran->screen(in vram)
	if (bIsSprite)
	{
		animation++;
		animation = animation >= SprintSizeX ? animation - SprintSizeX : animation;


		SDL_RenderCopy(GENGINE->MyRenderer, MyTexture, new SDL_Rect{ MySurface->w / SprintSizeX * animation,0,MySurface->w / SprintSizeX,MySurface->h / SprintSizeY}, new SDL_Rect{ X * Size,Y * Size,Size,Size });
	}
	else
	{
		SDL_RenderCopy(GENGINE->MyRenderer, MyTexture, nullptr, new SDL_Rect{ X * Size,Y * Size,Size,Size });
	}
	}
	

void AActor::LoadBmp(std::string FileName,SDL_Color ColorKey)
{
	
	MySurface = SDL_LoadBMP(FileName.c_str());
	SDL_SetColorKey(MySurface, SDL_TRUE, SDL_MapRGBA(MySurface->format,ColorKey.r, ColorKey.g, ColorKey.b, ColorKey.a));
	MyTexture= SDL_CreateTextureFromSurface(GENGINE->MyRenderer,MySurface);

}
