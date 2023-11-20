#include "SimpleEngine.h"

int main()
{
	FSimpleEngine* MyEngine = FSimpleEngine::GetInstance();

	MyEngine->LoadLevel("D:\\ETERBUS\\etaproject\\Engine\\Engine\\Map\\BMap.txt");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}