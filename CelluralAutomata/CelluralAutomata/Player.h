#pragma once
#ifndef PLR__
#define PLR__


#include "WorkManager.h"



class Player 
{
private:

	sf::Event event;

	sf::Vector2i origin;
	float zoomLevel = 0.f;
	int zoomLevel2 = 0;
	sf::Vector2f centerPos = {0, 0};


public:
	bool nextTurn = false;
	bool moving = false;
	sf::View camera;
	sf::View HUD;
	bool focus = false;
	sf::Text camerapos;
	void renderpos( sf::RenderWindow &window, std::string tiletype);
	bool settingsMenu = false;
	bool normal = true;
	Player(sf::Image &img);

	void Action(sf::RenderWindow &window, int &playerColor);
	void UpdateWindow(sf::RenderWindow &window);

	void CheckButtons(sf::RenderWindow& window);
};


#endif PLR__
