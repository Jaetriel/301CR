#include "playerClass.h"



playerClass::playerClass(sf::Vector2f spawnPoint, float speed,float sizeX, float sizeY, std::string tex) :position(spawnPoint), moveSpeed(speed) 
{
	type = player;
	rect.setSize(sf::Vector2f(sizeX, sizeY));
	rect.setFillColor(sf::Color::Magenta);
	rect.setPosition(spawnPoint);
	texture.loadFromFile(tex);
	sprite.setTexture(texture);
	sprite.setPosition(spawnPoint);
	isActive = true;
	isColliding = false;
};


entityClass* playerClass::clone(sf::Vector2f spawnPoint, float speed, float sizeX, float sizeY, std::string tex)
{
	std::cout << "Clone function called for player!" << std::endl;
	return new playerClass(spawnPoint,speed, sizeX, sizeY, tex);
}

playerClass::~playerClass()
{
}


void playerClass::moveLeft()
{
	leftPressed = true;
}

void playerClass::stopLeft()
{
	leftPressed = false;
}

void playerClass::moveRight()
{
	rightPressed = true;
}

void playerClass::stopRight()
{
	rightPressed = false;
}

void playerClass::moveUp()
{
	upPressed = true;
}

void playerClass::stopUp()
{
	upPressed = false;
}

void playerClass::moveDown()
{
	downPressed = true;
}

void playerClass::stopDown()
{
	downPressed = false;
}

 void playerClass::update()
{
	if (leftPressed)
	{
		sprite.move(sf::Vector2f(-moveSpeed , 0.0f));
	}

	if (rightPressed)
	{
		sprite.move(sf::Vector2f(moveSpeed , 0.0f));
	}

	if (upPressed)
	{
		sprite.move(sf::Vector2f(0.0f, -moveSpeed));
	}

	if (downPressed)
	{
		sprite.move(sf::Vector2f(0.0f, moveSpeed));
	}
	rect.setPosition(sprite.getPosition());
}
