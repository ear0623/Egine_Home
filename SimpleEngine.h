#pragma once

#include<vector>
#include<string>

#define GENGINE FSimpleEngine::GetInstance()

class UWorld;

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


protected:
	bool bIsRunning;
	UWorld* World;
	static FSimpleEngine* Instance;

	int input();
	void Tick(int KeyCode);
	void Render();

private:
	FSimpleEngine();
};

