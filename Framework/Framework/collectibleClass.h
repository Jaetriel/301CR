#pragma once
#include "entityClass.h"
#include <iostream>

class collectibleClass: public entityClass
{
public:
	collectibleClass(sf::Vector2f spawnPoint, float sizeX, float sizeY,std::string texDir);
	~collectibleClass();
	virtual entityClass* clone(sf::Vector2f spawnPoint, float sizeX, float sizeY,std::string texDir);
	virtual void update();
	float getScoreValue() { return scoreValue; }
	std::string textureDir;
private:
	sf::Vector2f position;
	float scoreValue = 10;
};

