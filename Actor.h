#pragma once
#include "SDL.h"
#include <iostream>

class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	AActor(int NewX, int NewY, char NewShape);
	AActor(int NewX, int NewY, char NewShape, int NewSortOrder);
	AActor(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color NewColor = SDL_Color{ 255,0,0,0 }, Uint8 size =32);
	~AActor();

	virtual void BeginePlay();
	virtual void Tick();
	virtual void Render();

	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { Y = NewY; }

	inline bool GetbCollide() const { return bCollide;}
	inline void SetCollide(bool NewColide) { bCollide = NewColide; }

	inline int GetSortOrder() const { return SortOrder; }
	inline void SetSortOrder(int NewSortOrder) { SortOrder = NewSortOrder; }

	virtual bool operator<(const AActor& RHS)const { return this->SortOrder < RHS.SortOrder; }
	
	SDL_Color color;
	Uint8 Size;
	SDL_Surface* MySurface;
	virtual void LoadBmp(std::string FileName, SDL_Color ColorKey=SDL_Color{255,255,255,0});
	SDL_Texture* MyTexture;
	bool bIsSprite;
	int SprintSizeX;
	int SprintSizeY;
	int animation;


protected:
	int X;
	int Y;

	int SortOrder;
	bool bCollide;
	char Shape;
	

private:

};

