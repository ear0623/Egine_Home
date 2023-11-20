#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	AGoal(int NewX, int NewY);
	AGoal(int NewX, int NewY, char NewShape);
	AGoal(int NewX, int NewY, char NewShape, int NewSortOrder);
	AGoal(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	virtual ~AGoal();

protected:


private:

};

