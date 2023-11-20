#pragma once
#include "Actor.h"

class AGoal;

class APlayer :  public AActor
{
public:

	APlayer();
	APlayer(int NewX, int NewY);
	APlayer(int NewX, int NewY, char NewShape);
	APlayer(int NewX, int NewY, char NewShape, int NewSortOrder);
	APlayer(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	~APlayer();

	virtual void Tick(int KeyCode) override;
	bool IsCollide(int NewX, int NewY);

	
protected:
	
private:

};

