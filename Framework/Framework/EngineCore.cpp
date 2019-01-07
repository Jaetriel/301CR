#include "EngineCore.h"



EngineCore::EngineCore(float height, float width, std::string name, std::string background)
{
	
	//constructor of engine creates window, loads background texture
	window.create(sf::VideoMode(width,height),name, sf::Style::Default);
	backgroundTexture.loadFromFile(background);
	backgroundSprite.setTexture(backgroundTexture);


	//make prototypes for player and collectible
	playerOnePrototype = new playerClass(sf::Vector2f(600.0f, 150.0f), 0.05f, 50.0f, 50.0f, "../Textures/enemy.png");
	observer.spawned(player, playerOnePrototype);
	coinPrototype = new collectibleClass(sf::Vector2f(150.0f, 150.0f),20.0f,20.0f,"../Textures/coin.png");
	observer.spawned(collectible, coinPrototype);
	coinPrototype->clone(sf::Vector2f(200.0f, 200.0f), 20.0f, 20.0f, "coin.png");
	


	//networking hopefully working

	//check if enet initialized correctly
	if (enet_initialize() == 0)
	{
		std::cout << "Enet initialised!" << "\n\n";
	}


	client = enet_host_create(NULL, 1, 2, 0, 0);

	if (client == NULL)
	{
		std::cout << "Client failed to initialise!" << "\n\n";
	}

	enet_address_set_host(&address, "localhost");
	address.port = 1234;

	//connect to server
	peer = enet_host_connect(client, &address, 2, 0);


	if (peer == NULL) {
		std::cout << "No available peers for initializing an ENet connection.\n";	
	}
	else
	{
		playerClass* playerTwoPrototype = new playerClass(sf::Vector2f(750.0f, 550.0f), 0.05f, 50.0f, 50.0f, "../Textures/enemy.png");
		observer.spawned(player, playerTwoPrototype);
		std::cout << "Player 2 spawned!" << std::endl;
	}
	luaScript = assetLoader::readToString("levelOne.lua");
}


EngineCore::~EngineCore()
{
	delete newPosition;
}

void EngineCore::start()
{

	while (window.isOpen())
	{
		//calls the three main functions to create a kind of basic game loop

		input();
		update();
		draw();
	}
}

