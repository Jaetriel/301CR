#include "EngineCore.h"

void EngineCore::input()
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			// Someone closed the window- bye
			window.close();
	}

	//player quit with escape
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		//disconnect on close
		if (peer != NULL)
		{
		enet_peer_disconnect_now(peer, 0);
		}
		enet_host_destroy(client);
		atexit(enet_deinitialize);

		window.close();
	}

	//player movement in a very naive way
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerOnePrototype->moveLeft();
	}
	else 
	{
		playerOnePrototype->stopLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerOnePrototype->moveRight();
	}
	else
	{
		playerOnePrototype->stopRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		playerOnePrototype->moveUp();
	}
	else
	{
		playerOnePrototype->stopUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		playerOnePrototype->moveDown();
	}
	else
	{
		playerOnePrototype->stopDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		dataPacket = enet_packet_create(&luaScript, sizeof(luaScript), ENET_PACKET_FLAG_RELIABLE);
		enet_host_broadcast(client, 0, dataPacket);



		//supposed to play sound when key is pressed ideally
		audioManager.loadSound("../Sounds/coinPickUp.aif");
		//audioManager.playSound("../Sounds/coinPickUp.aif");
	}
	
}