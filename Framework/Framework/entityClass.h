#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

enum  EntityType { player, enemy, collectible, wall };

class entityClass
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Texture texture;
	EntityType type;
	bool isActive;
	bool isColliding;

	virtual void update();
	//entityClass();
	virtual ~entityClass();
	virtual entityClass* clone(sf::Vector2f spawnPoint);
	sf::FloatRect getBounds() { return rect.getGlobalBounds(); }
};

