#include "World.h"
#include <algorithm>
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();//엔진은 월드에서만 책임져준다.
}

void UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		Actors.push_back(NewActor);
	}
}

void UWorld::Tick()
{
	for (const auto& Actor : Actors)
	{
		
		if (Actor)
		{
			Actor->Tick();
		}
		
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SortRenderOrder()
{
	std::sort(Actors.begin(), Actors.end(), [](const AActor* LHS, const AActor* RHS) {return LHS->GetSortOrder() < RHS->GetSortOrder(); });
}

