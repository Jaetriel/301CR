#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
//observer class to monitor what's being spawned and score
#include "observerClass.h"
//entity class+ child classes
#include "entityClass.h"
#include "playerClass.h"
#include "collectibleClass.h"
//fmod is the audio library
#include <fmod_studio.hpp>
#include <fmod.hpp>
//enet is the networking library
#include <enet\enet.h>
//audio manager class
#include "Audio.h"
#include "assetLoader.h"


struct Vector2 {
	float x;
	float y;
};

class EngineCore
{
public:
	EngineCore(float height, float width, std::string name, std::string background);
	~EngineCore();

	void start();
	sf::RenderWindow window;
private:

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	playerClass* playerOnePrototype;
	//player two for multiplayer
	playerClass* playerTwoPrototype;
	collectibleClass* coinPrototype;
	//store the info from received packets
	Vector2* newPosition = new Vector2;
	Audio audioManager;
	observerClass observer;
	void input();
	void update();
	void draw();
	std::string luaScript;

	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	ENetEvent enetEvent;
	ENetPacket* dataPacket;
};

