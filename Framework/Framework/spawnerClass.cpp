#include "spawnerClass.h"



spawnerClass::spawnerClass()
{
	
}


spawnerClass::~spawnerClass()
{
	while (spawnedPrototypes.size() != 0)
	{
		delete spawnedPrototypes.back();
		spawnedPrototypes.pop_back();
	}
}

void spawnerClass::addPrototype(entityClass* newPrototype)
{

	spawnedPrototypes.push_back(newPrototype);
	std::cout << "Added prototype of type: " << newPrototype->type << std::endl;
	
}
