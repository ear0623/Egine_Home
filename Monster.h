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

protected:

private:
};

