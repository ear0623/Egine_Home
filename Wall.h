#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:

	AWall();
	AWall(int NewX, int NewY);
	AWall(int NewX, int NewY, char NewShape);
	AWall(int NewX, int NewY, char NewShape, int NewSortOrder);
	AWall(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	virtual ~AWall();
protected:

private:
};

