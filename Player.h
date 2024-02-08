#pragma once
#include "Actor.h"
#include "SDL.h"

class AGoal;

class APlayer :  public AActor
{
public:

	APlayer();
	APlayer(int NewX, int NewY);
	APlayer(int NewX, int NewY, char NewShape);
	APlayer(int NewX, int NewY, char NewShape, int NewSortOrder);
	APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color Newcolor = SDL_Color{255,0,0,0},Uint8 size=32);
	~APlayer();

	virtual void Tick() override;
	virtual void Render()override;
	bool IsCollide(int NewX, int NewY);

	Uint64 ProcessTime;

	Uint64 ElaspedTime;//경과시간

	Uint8 SprintIndex;
	Uint8 SprintDeirection;
protected:
	
private:

};

