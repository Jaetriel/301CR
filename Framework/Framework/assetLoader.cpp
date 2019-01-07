
#include "assetLoader.h"

using namespace luabridge;

assetLoader::assetLoader()
{
	file = luaL_newstate();
	luaL_dofile(file, "../Framework/levelOne.lua");
	luaL_openlibs(file);
	lua_pcall(file, 0, 0, 0);
}


assetLoader::~assetLoader()
{
}

void assetLoader::loadWindow()
{

	//make a reference to the table window so we can access what's in it
	LuaRef t = getGlobal(file, "window");
	LuaRef title = t["title"];
	LuaRef w = t["width"];
	LuaRef h = t["height"];
	LuaRef tex = t["texture"];

	//cast the data to the appropriate types for our code
	windowTitle = title.cast<std::string>();
	windowWidth = w.cast<int>();
	windowHeight = h.cast<int>();
	backgroundTexDir = tex.cast<std::string>();
	std::cout << "Window loaded!" << std::endl;

}
// asset loader uses lua script to load in the coin texture path and other parameters set it to the variable
//tested to see if i can load the coin entity in with lua script editing but code breaks
void assetLoader::loadCoin()
{
	//make a reference to the table window so we can access what's in it
	LuaRef t = getGlobal(file, "coin");
	LuaRef pX = t["posX"];
	LuaRef pY = t["posY"];
	LuaRef sX = t["sizeX"];
	LuaRef sY = t["sizeY"];

	LuaRef coinTex = t["texture"];

	posX = pX.cast<float>();
	posY = pY.cast<float>();
	sizeX = sX.cast<float>();
	sizeY = sY.cast<float>();
	coinTexDir = coinTex.cast<std::string>();
	//collectibleClass* coinOne = new collectibleClass(sf::Vector2f(posX, posY), sizeX, sizeY, coinTexDir);
	//obs.spawned(collectible, coinOne);
}

void assetLoader::loadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;

	if (texture.loadFromFile(fileName))
	{
		std::cout << "Texture loaded successfully: ";
		texturesMap.emplace(name, texture);
		std::map<std::string, sf::Texture&>::iterator it;
		it = texturesMap.find(name);
		std::cout << it->first << std::endl;
	}
}

sf::Texture& assetLoader::getTexture(std::string name)
{
	std::map<std::string, sf::Texture&>::iterator it;
	it = texturesMap.find(name);
	return it->second;
}

std::string assetLoader::readToString(const std::string& fileName)
{
	std::string data;
	std::ifstream in(fileName.c_str());
	getline(in, data, std::string::traits_type::to_char_type(
		std::string::traits_type::eof()));
	return data;
}

