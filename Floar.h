#pragma once
#include "Actor.h"
class AFloar :  public AActor
{
public:

	AFloar();
	AFloar(int NewX, int NewY);
	AFloar(int NewX, int NewY, char NewShape);
	AFloar(int NewX, int NewY, char NewShape, int NewSortOrder);
	AFloar(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	~AFloar();


protected:

private:

};

