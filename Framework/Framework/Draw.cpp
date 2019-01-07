#include "EngineCore.h"



void EngineCore::draw()
{
	//clear out from last frame
	window.clear(sf::Color::White);



	//draw background
	window.draw(backgroundSprite);
	
	//a for loop that checks the objectsMap to see which objects are active so it draws only them
	//not well implemented because objectsVect is public in observer class which is far from ideal
	for (int i = 0; i < observer.objectsVect.size(); i++)
	{
		if (observer.objectsVect[i]->isActive)
		{
			window.draw(observer.objectsVect[i]->sprite);
		}
	}


	window.display();
}