#include "collectibleClass.h"



collectibleClass::collectibleClass(sf::Vector2f spawnPoint, float sizeX, float sizeY,std::string texDir): position(spawnPoint)
{
	type = collectible;
	rect.setSize(sf::Vector2f(sizeX, sizeY));
	rect.setFillColor(sf::Color::Magenta);
	rect.setPosition(spawnPoint);
	texture.loadFromFile(texDir);
	sprite.setTexture(texture);
	sprite.setPosition(spawnPoint);
	isActive = true;
}

entityClass* collectibleClass::clone(sf::Vector2f spawnPoint, float sizeX, float sizeY,std::string texDir)
{
	std::cout << "Clone function called for player!" << std::endl;
	return new collectibleClass(spawnPoint,sizeX,sizeY,texDir);
}

void collectibleClass::update()
{
}


collectibleClass::~collectibleClass()
{
}
