#include "SimpleEngine.h"
#include <iostream>
#include <fstream>


int SDL_main(int argc,char* argv[])
{
	
	FSimpleEngine* MyEngine = FSimpleEngine::GetInstance();

	MyEngine->LoadLevel("Data/Level01.smap");
	MyEngine->Run();

	delete MyEngine;

	return 0;
}