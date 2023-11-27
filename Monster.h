#pragma once

#include "Actor.h"
class AMonster : public AActor
{
public:

	AMonster();
	AMonster(int NewX, int NewY);
	AMonster(int NewX, int NewY, char NewShape);
	AMonster(int NewX, int NewY, char NewShape, int NewSortOrder);
	AMonster(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	virtual ~AMonster();

	virtual void Tick() override;
	bool IsCollide(int NewX, int NewY);
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