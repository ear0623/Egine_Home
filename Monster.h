#pragma once

#include "Actor.h"
class AMonster : public AActor
{
public:

	AMonster();
	AMonster(int NewX, int NewY);
	AMonster(int NewX, int NewY, char NewShape);
	AMonster(int NewX, int NewY, char NewShape, int NewSortOrder);
	AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide, SDL_Color Newcolor = SDL_Color{ 0,0,255,0 }, Uint8 size = 32);

	virtual ~AMonster();

	virtual void Tick() override;
	bool IsCollide(int NewX, int NewY);

	Uint64 ProcessTime;

	Uint64 ElaspedTime;//경과시간
protected:

private:
};


enum class EMonsterDirection
{
	Left = 0,
	Right = 1,
	Down = 2,
	Up = 3,
};