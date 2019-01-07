#include "Audio.h"



Audio::Audio()
{
	//create fmod studio system
	FMOD::Studio::System* system = NULL;
	FMOD::Studio::System::create(&system);

	if (system) {
		std::cout << "High-level (fmod studio) audio system created." << "\n";
	}

	//create fmod system pointer and bind it to the studio system

	FMOD::System* lowLevelSystem = NULL;
	system->getLowLevelSystem(&lowLevelSystem);

	if (lowLevelSystem) {
		std::cout << "Low-level (fmod) audio system created." << "\n";
	}

	//system setup

	lowLevelSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_STEREO, 0);
	system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, NULL);
}


Audio::~Audio()
{
	system->unloadAll();
	system->release();
}

void Audio::loadSound(const std::string& strSoundName)
{

	FMOD::Sound* pSound = NULL;
	lowLevelSystem->createSound(strSoundName.c_str(), FMOD_LOOP_OFF, NULL, &pSound);

	if (pSound)
	{
		std::cout << "Sound loaded." << "\n";
		//if everything was okay add sound to map
		soundMap[strSoundName] = pSound;
	}
	
}

void Audio::playSound(const std::string& strSoundName)
{
	//find sound in map using iterator and play it
	
	sound = soundMap.find(strSoundName);
	FMOD::Channel* pChannel = NULL;

	lowLevelSystem->playSound(sound->second, NULL, false, &pChannel);
}

void Audio::update()
{
	system->update();
}
