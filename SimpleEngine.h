#pragma once

#include<vector>
#include<string>


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

	static int KeyCode;
	static AGameState* GetGamestate() { return GetInstance()->GameState; }
	static AGameMode* GetGameMode() { return GetInstance()->GameMode; }
protected:
	bool bIsRunning;
	UWorld* World;
	static FSimpleEngine* Instance;
	 AGameMode* GameMode;
	AGameState* GameState;

	void input();
	void Tick();
	void Render();

private:
	FSimpleEngine();
};

