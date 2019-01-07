#pragma once
#include <iostream>
#include <vector>
#include "entityClass.h"
#include "observerClass.h"

class spawnerClass
{
public:
	spawnerClass();
	~spawnerClass();
	void addPrototype(entityClass* newPrototype);
	entityClass* getPrototype(int i) { return spawnedPrototypes.at(i); };
private:
	std::vector<entityClass*> spawnedPrototypes;
	
};

