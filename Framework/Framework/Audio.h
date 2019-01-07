#pragma once
#include <fmod_studio.hpp>
#include <fmod.hpp>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
class Audio
{
public:
	Audio();
	~Audio();
	void loadSound(const std::string& strSoundName);
	void playSound(const std::string& strSoundName);
	void update();
private:
	FMOD::Studio::System* system;
	FMOD::System* lowLevelSystem;
	std::map<std::string, FMOD::Sound*> soundMap;
	std::map<std::string, FMOD::Sound*>::iterator sound;
};

