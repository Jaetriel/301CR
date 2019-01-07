#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include "collectibleClass.h"
#include "observerClass.h"
//including lua and luabridge
//extern C is because lua is compiled in C instead of C++
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <LuaBridge\LuaBridge.h>

class assetLoader
{
public:
	assetLoader();
	~assetLoader();
	void loadWindow();
	void loadCoin();
	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);
	//reads lua script into a string
	static std::string readToString(const std::string& fileName);

	//window parameters for lua script
	int windowWidth;
	int windowHeight;
	std::string windowTitle;
	std::string backgroundTexDir;

	//coin parameters for lua script
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	std::string coinTexDir;
private:
	std::string luaAsStr;
	observerClass obs;
	//lua script we want to load
	lua_State * file;
	//map containing all loaded textures
	std::map<std::string, sf::Texture&> texturesMap;
};

