#include "Player.h"
#include "HUD.h"

Player::Player(sf::Image &img)
{
	camera.setCenter(img.getSize().x/2, img.getSize().y/2);
	camera.setSize(ScreenWidth, ScreenHeight);
	//sf::View viewLeft(sf::FloatRect(0, 0, upper_bar.getSize().x, upper_bar.getSize().y));
	HUD.setViewport(sf::FloatRect(0, 0, 1, 1));

	
	
}

void Player::Action(sf::RenderWindow &window, int &playerColor)

{

	window.clear();
	
	if (sf::Mouse::getPosition(window).x > ScreenWidth)sf::Mouse::setPosition(sf::Vector2i(ScreenWidth - 3, sf::Mouse::getPosition(window).y), window);
	if (sf::Mouse::getPosition(window).y > ScreenHeight)sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, ScreenHeight - 3), window);
	if (sf::Mouse::getPosition(window).x < 0)sf::Mouse::setPosition(sf::Vector2i(3, sf::Mouse::getPosition(window).y), window);
	if (sf::Mouse::getPosition(window).y < 0)sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition(window).x, 3), window);

	if (moving == true && settingsMenu == false)
	{

		sf::Vector2i destination = sf::Mouse::getPosition(window);
		if (camera.getCenter().x > 0 && camera.getCenter().x < width * 16 && camera.getCenter().y > 0 && camera.getCenter().y < height * 16)
			camera.move(sf::Vector2f(destination - origin) / float(MoveSpeed));
		else
		{
			sf::Vector2f back = camera.getCenter();
			if(back.x<10)
			camera.setCenter(back.x+10,back.y);
			if(back.y<10)
			camera.setCenter(back.x, back.y+10);
			if(back.x > width * 16 - 10)
			camera.setCenter(back.x - 10, back.y);
			if (back.y > height * 16 - 10)
				camera.setCenter(back.x, back.y-10);
		}
		
		
	}

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed)
		{



			if (event.mouseButton.button == sf::Mouse::Middle && settingsMenu == false)
			{
				origin = sf::Mouse::getPosition(window);
				moving = true;
			}
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > 0 && window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > 0 && window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < width * 16 && window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < height * 16)
				{
					focus = true;
					focusCoord.x = (int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16));
					focusCoord.y = (int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16));
				}
				window.setView(HUD);

				if(buttons[exitB].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))window.close();

				if (settingsMenu == true && buttons[settingsB].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					settingsMenu = false;
					continue;
				}
				if (settingsMenu == false && buttons[settingsB].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					ShowSettings(window);
					settingsMenu = true;
				}
				if (settingsMenu == true && settingButton[exitS].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					settingsMenu = false;
					continue;
				}
				for (int i = 0; i < 15; i++)
				{
					if ((playerColor == 0 && colors[i].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))))))
					{
						playerColor = i;
					}
				}
				window.setView(settingBlock.menuCamera);

				if (settingsMenu == true&&fullscreenBR == true && settingButton[fullscreenS].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					fullscreenBR = false;
					window.close();
					window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Pixel Empire", sf::Style::Default);
					window.setMouseCursorVisible(false);
					
					std::cout << fullscreenBR;
					continue;
				}
				if (settingsMenu == true && fullscreenBR == false && settingButton[fullscreenS].CheckMouse(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)))))
				{
					fullscreenBR = true;
					window.close();
					window.create(sf::VideoMode(ScreenWidth, ScreenHeight), "Pixel Empire", sf::Style::Fullscreen);
					window.setMouseCursorVisible(false);
					
					std::cout << fullscreenBR;
					continue;
				}

				
				
				window.setView(camera);
			}


		}
		if (event.type == sf::Event::MouseButtonReleased)
		{

			moving = false;
		}


		if (event.type == sf::Event::MouseWheelMoved && settingsMenu==false)
		{
			if (event.mouseWheel.delta > 0 && zoomLevel2 < 10)
			{
				zoomLevel += 0.1f;
				std::cout << zoomLevel << std::endl;
				camera.zoom(1-zoomLevel);
				zoomLevel = 0;
				zoomLevel2++;
				
				CursorSize -= 0.066666f;
			}
			if (event.mouseWheel.delta < 0 && zoomLevel2>0)
			{
				zoomLevel -= 0.1111f;
				std::cout << zoomLevel << std::endl;
				camera.zoom(1-zoomLevel);
				zoomLevel = 0;
				zoomLevel2--;
				CursorSize += 0.066666f;
				
			}
		}
		if (event.type == sf::Event::MouseWheelMoved && settingsMenu == true)
		{
			if (event.mouseWheel.delta > 0 && settingBlock.menuCamera.getCenter().y > 20)
			{
				settingBlock.menuCamera.move(sf::Vector2f(0,-5));
			}
			if (event.mouseWheel.delta < 0 && settingBlock.menuCamera.getCenter().y < 100)
			{

				settingBlock.menuCamera.move(sf::Vector2f(0, 5));
			}
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Q)
			{
				sf::Color* col = new sf::Color;
				col->b = 0;
				col->g = 0;
				col->r = 255 - playerColor;

				empires.setPixel(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16, window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16, *col);
					delete col;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				sf::Color* col = new sf::Color;
				col->b = 0;
				col->g = 254;
				col->r = 0;

				worldImg.setPixel(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16, window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16, *col);
				
				delete col;
			}
			if (event.key.code == sf::Keyboard::Z && testingColor > 0)
			{
				testingColor--;
			}
			if (event.key.code == sf::Keyboard::X && testingColor < 16)
			{
				testingColor++;
			}
		}
		moved = true;
	}
	UpdateTexts();
	window.setView(camera);
}

void Player::UpdateWindow(sf::RenderWindow &window)
{
	window.setView(camera);
}

void Player::renderpos( sf::RenderWindow &window, std::string tiletype)
{
	
	camerapos.setFont(defaultfont);
	camerapos.setString(std::to_string(int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x/16)) + ", " + std::to_string(int(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y/16))+", "+tiletype+" "+std::to_string(worldImg.getPixel(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x / 16, window.mapPixelToCoords(sf::Mouse::getPosition(window)).y / 16).g));
	camerapos.setPosition(24, 8);
	
	window.setView(HUD);
	window.draw(camerapos);
	window.setView(camera);
}

void Player::CheckButtons(sf::RenderWindow& window)
{
	window.setView(HUD);
	for (int i = 0; i < 50; i++)
	{
		if(buttons[i].CheckMouse(window.mapPixelToCoords(sf::Mouse::getPosition(window))))buttons[i].Focus();
	}
	for (int i = 0; i < 15; i++)
	{
		if (colors[i].CheckMouse(window.mapPixelToCoords(sf::Mouse::getPosition(window))))colors[i].Focus();
	}

	if (settingButton[0].CheckMouse(window.mapPixelToCoords(sf::Mouse::getPosition(window))))settingButton[0].Focus();
	window.setView(settingBlock.menuCamera);
	for (int i = 1; i < 10; i++)
	{
		if (settingButton[i].CheckMouse(window.mapPixelToCoords(sf::Mouse::getPosition(window))))settingButton[i].Focus();
	}

	window.setView(camera);
}