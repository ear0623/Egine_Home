#include "SimpleEngine.h"
#include "string"

int main()
{
	FSimpleEngine* MyEngine = FSimpleEngine::GetInstance();

	MyEngine->LoadLevel("a.map");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}