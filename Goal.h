#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	AGoal(int NewX, int NewY);
	AGoal(int NewX, int NewY, char NewShape);
	AGoal(int NewX, int NewY, char NewShape, int NewSortOrder);
	AGoal(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color Newcolor = SDL_Color{ 255,0,0,0 }, Uint8 size = 32);
	virtual ~AGoal();

protected:


private:

};

