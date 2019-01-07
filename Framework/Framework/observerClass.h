#pragma once
#include <iostream>
#include "entityClass.h"
#include <map>

//enum  EntityType { player, enemy, collectible, wall };

//observer mainly to keep track of score
class observerClass
{
public:
	int score;
	observerClass();
	~observerClass();

	
	void updateScore(entityClass *entity);
	void spawned(EntityType type, entityClass* entity);

	std::vector<entityClass*> objectsVect;
};

