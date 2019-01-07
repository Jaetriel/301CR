#include "observerClass.h"



observerClass::observerClass()
{
	score = 0;

}


observerClass::~observerClass()
{
}

void observerClass::spawned(EntityType type, entityClass* entity)
{
	objectsVect.push_back(entity);
	std::cout << "Put an object of type " << type << " into the map!" << std::endl;
}

//update score to be called when player collides 
void observerClass::updateScore(entityClass* entity)
{
	//looks through the vector to find entity and then checks it's type
	for (int i = 0; i < objectsVect.size(); i++)
	{
		if (objectsVect[i] == entity)
		{
			switch (entity->type)
			{
			case EntityType::collectible:
				score += 10;
				std::cout << "Gained 10 score!" << std::endl;
				//if it's a coin then we pick it up so we need to remove it from vector
				objectsVect.erase(objectsVect.begin() + i);
				break;
			case EntityType::enemy:
				score = 0;
				std::cout << "Hit an enemy, score is set back to 0!" << std::endl;
				
				break;
			case EntityType::player:
				// do something
				break;
			}
			
		}
		else if(i ==  (objectsVect.size() - 1))
			std::cout << "Object not found!" << std::endl;
	}
	
}
