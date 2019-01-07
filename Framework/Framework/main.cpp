#include "EngineCore.h"
#include "assetLoader.h"



int main()
{
	assetLoader loader;
	loader.loadWindow();

	EngineCore engine(loader.windowHeight,loader.windowWidth,loader.windowTitle,loader.backgroundTexDir);
	
	std::cout << "Lua script loaded in is: " << std::endl;
	std::string script = loader.readToString("levelOne.lua");
	std::cout << script << std::endl;
	engine.start();

	
	
	return 0;
}