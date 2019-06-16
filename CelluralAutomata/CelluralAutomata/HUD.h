#pragma once
#include "WorkManager.h"
#include "Button.h"

inline void DrawHUD(sf::RenderWindow& window, sf::View camera)
{
	window.setView(camera);
	window.draw(upper_bar);
	
}
class MenuBlock
{
public:
	sf::View menuCamera;
	sf::RectangleShape appearance;



	MenuBlock(sf::Vector2f position, sf::Vector2f size)
	{

		appearance.setTexture(&menu_barT);
		appearance.setPosition(position);
		appearance.setSize(size);
		menuCamera.setSize(appearance.getSize());
		menuCamera.setCenter(appearance.getPosition().x + appearance.getSize().x / 2, appearance.getPosition().y + appearance.getSize().y / 2);
		menuCamera.setViewport(sf::FloatRect(0.25, 0.25, 0.49, 0.65));
	}
	void Draw(sf::RenderWindow & window)
	{
		window.draw(appearance);
	}

};

inline Button settingButton[10];
enum settingButtons { exitS = 0 , fullscreenS = 1};
inline MenuBlock settingBlock(sf::Vector2f(0,0), sf::Vector2f(100,100));

inline void GenerateSettingsButtons()
{

	settingButton[exitS].appearance = Buttons::exitR;
	settingButton[exitS].appearance.setPosition(sf::Vector2f(ScreenWidth / 8 + 4, ScreenHeight / 8 + 4));
	settingButton[exitS].pos = sf::Vector2f(ScreenWidth / 8 + 8, ScreenHeight / 8 + 8);
	settingButton[exitS].size = Buttons::exitR.getSize();


	settingButton[fullscreenS].appearance.setTexture(&upper_barT);
	settingButton[fullscreenS].appearance.setPosition(5,5);
	settingButton[fullscreenS].appearance.setSize(sf::Vector2f(40, 10));
	settingButton[fullscreenS].pos = sf::Vector2f(5,5);
	settingButton[fullscreenS].size = sf::Vector2f(40, 10);

}

inline void ShowSettings(sf::RenderWindow& window)
{

	window.draw(menuR);
	window.draw(settingButton[0].appearance);

	window.setView(settingBlock.menuCamera);
	settingBlock.Draw(window);

	for (int i = 1; i < 10; i++)
	{
		window.draw(settingButton[i].appearance);
		window.draw(textsSettings[i]);
	}

}





