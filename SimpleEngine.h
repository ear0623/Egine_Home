#pragma once

#include<vector>
#include<string>
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")


#define GENGINE FSimpleEngine::GetInstance()

class UWorld;
class AActor;
class AGameMode;
class AGameState;


class FSimpleEngine
{
public:
	virtual ~FSimpleEngine();
	
	void Init();

	void Run();

	void Stop();

	void Term();
	//
	void LoadLevel(std::string FileName);

	

	inline UWorld* GetWorld() const { return World; };

	static FSimpleEngine* GetInstance() 
	{
		if (Instance == nullptr)
		{
			Instance = new FSimpleEngine();
		}
		return Instance;
	}

	static SDL_Keycode KeyCode;
	static AGameState* GetGamestate() { return GetInstance()->GameState; }
	static AGameMode* GetGameMode() { return GetInstance()->GameMode; }
	static Uint64 GetWorldDeltaSecons(){return GetInstance()->DeltaSeconds;}

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
	Uint64 DeltaSeconds;
	Uint64 LastTime;

protected:
	bool bIsRunning;
	UWorld* World;
	static FSimpleEngine* Instance;
	 AGameMode* GameMode;
	AGameState* GameState;

	void input();
	void Tick();
	void Render();
	void LoadActor(int NewX, int NewY, char Actor);

	
private:
	FSimpleEngine();
};

