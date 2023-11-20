#pragma once

#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	~UWorld();

	void SpawnActor(AActor* NewActor);
	void Tick(int KeyCode);
	void Render();

	void SortRenderOrder();

	const std::vector<AActor*>& GetAllactors() { return Actors; }
	
protected:
	std::vector<AActor*> Actors;

private:

};

