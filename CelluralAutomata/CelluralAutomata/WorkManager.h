#pragma once

#include "ResourceManager.h"
#include "TextureManager.h"
#include "strings_PL.h"
#include "HUD.h"


inline void LoadMap(std::string filename, sf::Image &worldImage)
{
	if (worldImage.loadFromFile("Assets/Maps/" + filename + ".bmp")) 
	{
		std::cout << "Loaded map!";
	}

	if (empires.loadFromFile("Assets/Maps/test_empires.bmp"))
	{
		std::cout << "Loaded empires!";
	}

	std::cout << empires.getSize().x;


	width = worldImage.getSize().x;
	height = worldImage.getSize().y;



}



inline void LoadTextures()
{


	
	focuser.loadFromFile("Assets/Tiles/bend.png");
	focusershape.setTexture(&focuser);
	focusershape.setSize(sf::Vector2f(16, 16));

	menu_barT.loadFromFile("Assets/Tiles/bar.bmp");

	bar_horizontalT.loadFromFile("Assets/Tiles/bar_horizontal.bmp");
	bar_horizontal.setTexture(&bar_horizontalT);
	bar_horizontal.setSize(sf::Vector2f((width+2)*16, 16));
	bar_horizontal.setPosition(-16, -16);
	bar_horizontal2.setTexture(&bar_horizontalT);
	bar_horizontal2.setSize(sf::Vector2f((width + 2) * 16, 16));
	bar_horizontal2.setPosition(-16, height*16);

	bar_verticalT.loadFromFile("Assets/Tiles/bar_vertical.bmp");
	bar_verical.setTexture(&bar_verticalT);
	bar_verical.setSize(sf::Vector2f(16, (height+2)*16));
	bar_verical.setPosition(-16, -16);
	bar_verical2.setTexture(&bar_verticalT);
	bar_verical2.setSize(sf::Vector2f(16, (height + 2) * 16));
	bar_verical2.setPosition(width*16, -16);

	upper_barT.loadFromFile("Assets/Tiles/upper_bar.bmp");
	upper_bar.setTexture(&upper_barT);
	upper_bar.setSize(sf::Vector2f(ScreenWidth, ScreenHeight/13));
	upper_bar.setPosition(0, 0);

	Buttons::exitT.loadFromFile("Assets/Buttons/exit.png");
	Buttons::exitR.setTexture(&Buttons::exitT);
	Buttons::exitR.setSize(sf::Vector2f(ScreenWidth/90,ScreenHeight/67));
	Buttons::exitR.setPosition(0, 0);

	Buttons::settingsT.loadFromFile("Assets/Buttons/settings.png");
	Buttons::settingsR.setTexture(&Buttons::settingsT);
	Buttons::settingsR.setSize(sf::Vector2f(ScreenWidth / 90, ScreenHeight / 67));
	Buttons::settingsR.setPosition(0, 18);

	colorbars.loadFromFile("Assets/Tiles/borders.png");

	menuT.loadFromFile("Assets/Buttons/menu.png");
	menuR.setTexture(&menuT);
	menuR.setSize(sf::Vector2f(512, 780));
	menuR.setPosition(ScreenWidth / 8, ScreenHeight / 8);

	colorBar.setTexture(&upper_barT);
	colorBar.setSize(sf::Vector2f(280, 25));
	colorBar.setPosition(ScreenWidth / 6, ScreenHeight / 6);


	for (int i = 0; i < 15; i++)
	{
		Buttons::colors[i].setFillColor(colorbars.getPixel(17, 16 * i));
		Buttons::colors[i].setSize(sf::Vector2f(16, 16));
		Buttons::colors[i].setPosition(ScreenWidth / 6 + i * 18 + 10, ScreenHeight / 6 + 5);
	}

	Buttons::defaultButtonT.loadFromFile("Assets/Buttons/exit.png");
	Buttons::defaultButton.setTexture(&Buttons::defaultButtonT);
	Buttons::defaultButton.setSize(sf::Vector2f(ScreenWidth / 90, ScreenHeight / 67));
	Buttons::defaultButton.setPosition(-10,-10);



	defaultfont.loadFromFile("Dos.ttf");
}

inline void LoadText()
{
	Lang::stringsSettings[fullscreenS] = "PELNY EKRAN:  ";

	for (int i = 0; i < 10; i++)
	{
		textsSettings[i].setFont(defaultfont);
		textsSettings[i].setScale(0.1,0.1);
		textsSettings[i].setString(Lang::stringsSettings[i]);
		textsSettings[i].setPosition(settingButton[i].pos.x + 3, settingButton[i].pos.y + 3);
	}
	wybierz_kolor.setFont(defaultfont);
	wybierz_kolor.setScale(0.5, 0.5);
	wybierz_kolor.setString("Wybierz kolor: ");
	wybierz_kolor.setPosition(ScreenWidth / 6 + 40, ScreenHeight / 6 - 20);

}
inline void UpdateTexts()
{
	textsSettings[fullscreenS].setString(Lang::stringsSettings[fullscreenS] + std::to_string(fullscreenBR));
}

inline void LoadCursors()
{


	Cursors::normal.loadFromFile("Assets/Cursors/normal.png");
	Cursors::normalS.setTexture(&Cursors::normal);
	Cursors::normalS.setSize(sf::Vector2f(32, 32));

	Cursors::moving.loadFromFile("Assets/Cursors/moving.png");
	Cursors::movingS.setTexture(&Cursors::moving);
	Cursors::movingS.setSize(sf::Vector2f(32, 32));


}

inline void LoadMap()
{
	LoadMap(filename, worldImg);
	mapTxt.loadFromImage(worldImg);

	mapshape.setTexture(&mapTxt);
	mapshape.setSize(sf::Vector2f(worldImg.getSize()));
	std::cout << "Map loaded";

}

inline void DrawBars(sf::RenderWindow & window)
{
	window.draw(bar_horizontal);
	window.draw(bar_horizontal2);
	window.draw(bar_verical);
	window.draw(bar_verical2);
}

inline void UpdateCursors(sf::RenderWindow& window)
{
	Cursors::normalS.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	Cursors::normalS.setScale(CursorSize, CursorSize);

	Cursors::movingS.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	Cursors::movingS.setScale(CursorSize, CursorSize);
}



