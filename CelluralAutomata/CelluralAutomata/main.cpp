


#include "Loader.h"




int main()
{
	

	if (ScreenHeight != 1080 && ScreenWidth != 1920)
	{
		std::cout << "Wczytano okno bez pelnego ekranu!";
		fullscreen = sf::Style::Default;
		fullscreenBR = false;
	}
	else
	{
		fullscreenBR = true;
		fullscreen = sf::Style::Fullscreen;
		std::cout << "wczytano okno z pelnym ekranem!";
	}

	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Pixel Empire", fullscreen);

	window.setMouseCursorVisible(false);
	
	LoadEngine();

	Player pl1(worldImg);
	TileMap worldMap;

	sf::Color color;
	color.r = 255;
	color.g = 0;
	color.b = 0;
	empirec playerEmpire(0);
	


	if (!worldMap.load("Assets/Tiles/tilemap.bmp", sf::Vector2u(16, 16), height, width))
		return -1;

	window.setView(pl1.camera);
	int p = 0;
	
	


	while (window.isOpen())
	{
		
		
		

		p++;
		std::cout << p;
		


		while (pl1.nextTurn == false)
		{
			
			
			pl1.Action(window, playerEmpire.colorId);
			pl1.CheckButtons(window);

			UpdateCursors(window);
			elapsed = animateTime.getElapsedTime();

			if (elapsed >= speed)
			{
				worldMap.Animate(sf::Vector2u(16, 16), height, width, pl1.camera);
				animateTime.restart();
			};

			
			worldMap.UpdateMap2(sf::Vector2u(16, 16), height, width, pl1.camera, playerEmpire.color);
			worldMap.Update(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16, window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16), sf::Vector2u(16, 16));
			window.draw(worldMap);
			
			

			if (pl1.focus == true)
			{
				worldMap.maptile[focusCoord.x][focusCoord.y].Focus(window);
			}

			DrawBars(window);
			DrawHUD(window, pl1.HUD);
			DrawButtons(window);
			if (playerEmpire.colorId == 0)
			{
				window.draw(wybierz_kolor);
				window.draw(colorBar);
				ShowColors(window);
			}
			if (pl1.settingsMenu)
			{
				ShowSettings(window);
			}
			window.setView(pl1.camera);

			if ((window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16) > 0 && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16) > 0 && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16) < width && (window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16) < height && sf::Mouse::getPosition(window).y>=upper_bar.getSize().y)
				pl1.renderpos(window, worldMap.getTileType(int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16), int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16)));

			for (int i = 0; i < 50; i++)
			{
				buttons[i].Unfocus();
			}
			for (int i = 0; i < 10; i++)
			{
				settingButton[i].Unfocus();
			}
			for (int i = 0; i < 15; i++)
			{
				colors[i].appearance = Buttons::colors[i];
			}

			

			if (pl1.moving)
			{
				window.draw(Cursors::movingS);
			}else window.draw(Cursors::normalS);
			
			window.display();
		
		}

		window.clear();


		pl1.nextTurn = false;



	}
	


}