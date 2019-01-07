#pragma once
#include "entityClass.h"
#include <iostream>

class playerClass: public entityClass
{
public:
	playerClass(sf::Vector2f spawnPoint, float speed, float sizeX, float sizeY, std::string tex);
	~playerClass();
	virtual entityClass* clone(sf::Vector2f spawnPoint, float speed, float sizeX, float sizeY, std::string tex);
	virtual void update();
	//movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

private:
	sf::Vector2f position;
	float moveSpeed;
	//direction the character is moving in
	bool leftPressed;
	bool rightPressed;
	bool upPressed;
	bool downPressed;
};

