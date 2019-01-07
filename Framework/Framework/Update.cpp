#include "EngineCore.h"

void EngineCore::update()
{
	// here you would call the updates of all entities(game objects) in the game who have their own implementation of update
	for (int i = 0; i < observer.objectsVect.size(); i++)
	{
		observer.objectsVect[i]->update();
	}
	audioManager.update();

	//collision detection
	//very primitive way of doing it will work on later if there's time left
	if (playerOnePrototype->rect.getGlobalBounds().intersects(coinPrototype->rect.getGlobalBounds()))
	{
		if (playerOnePrototype->isColliding == false)
		{
			playerOnePrototype->isColliding = true;
			std::cout << "Collision detected!" << std::endl;
			//when player hits something call updateScore with that entity
			observer.updateScore(coinPrototype);
			coinPrototype->isActive = false;
			
		}
	}

	

	while (enet_host_service(client, &enetEvent, 0) > 0)
	{
		switch (enetEvent.type) {


		case ENET_EVENT_TYPE_RECEIVE:
			std::cout << "Packet received!\n";
			memcpy(newPosition, enetEvent.packet->data, enetEvent.packet->dataLength);
			std::cout << newPosition->x << "," << newPosition->y << "\n";
			//acess violation thrown at this line
			//playerTwoPrototype->sprite.move(sf::Vector2f(newPosition->x, newPosition->y));
			break;
		}
	}
	
}