#pragma once
#include "WorkManager.h"

class Button
{
public:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape appearance;


public:


	bool CheckMouse(sf::Vector2f mousepos)
	{
		if (mousepos.x > pos.x && mousepos.x < size.x + pos.x && mousepos.y > pos.y && mousepos.y < size.y + pos.y)return true;
		else return false;
	};

	Button(sf::RectangleShape& appear = Buttons::defaultButton)
	{
		pos = appear.getPosition();
		size = appear.getSize();
		appearance = appear;

	};

	void Focus()
	{

			appearance.setFillColor(sf::Color(120, 120, 120, 120));
	}
	void Unfocus()
	{
			appearance.setFillColor(sf::Color(255, 255, 255, 255));
	}
};

inline Button buttons[50];
inline Button colors[15];
enum buttonsEnum { exitB = 0 , settingsB = 1};

inline void UpdateButtons()
{
	buttons[exitB].appearance = Buttons::exitR;
	buttons[exitB].pos = Buttons::exitR.getPosition();
	buttons[exitB].size = Buttons::exitR.getSize();

	buttons[settingsB].appearance = Buttons::settingsR;
	buttons[settingsB].pos = Buttons::settingsR.getPosition();
	buttons[settingsB].size = Buttons::settingsR.getSize();

	for (int i = 0; i < 15; i++)
	{
		colors[i].appearance = Buttons::colors[i];
		colors[i].pos = Buttons::colors[i].getPosition();
		colors[i].size = sf::Vector2f(16, 16);
	}

}

inline void ShowColors(sf::RenderWindow& window)
{
	for (int i = 0; i < 15; i++)
	{
		window.draw(colors[i].appearance);
	}
}

inline void DrawButtons(sf::RenderWindow& window)
{
	for (int i = 0; i < 50; i++)
	{
		window.draw(buttons[i].appearance);
	}

	
}