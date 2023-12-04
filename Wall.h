#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:

	AWall();
	AWall(int NewX, int NewY);
	AWall(int NewX, int NewY, char NewShape);
	AWall(int NewX, int NewY, char NewShape, int NewSortOrder);
	AWall(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color Newcolor = SDL_Color{ 255,0,0,0 },Uint8 size=32);
	virtual ~AWall();
protected:

private:
};

