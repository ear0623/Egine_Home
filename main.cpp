#include "SimpleEngine.h"

int main()
{
	FSimpleEngine* MyEngine = FSimpleEngine::GetInstance();

	MyEngine->LoadLevel("C:\\Work\\L20231121Home\\Egine_Home\\MapAmap.txt");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}