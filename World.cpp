#include "World.h"
#include <algorithm>
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::SpawnActor(AActor* NewActor)
{
	if (NewActor)
	{
		Actors.push_back(NewActor);
	}
}

void UWorld::Tick(int KeyCode)
{
	for (const auto& Actor : Actors)
	{
		Actor->Tick(KeyCode);
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

