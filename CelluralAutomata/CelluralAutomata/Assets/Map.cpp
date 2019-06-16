#include "Map.h"


void Map::Draw(sf::RenderWindow &window, sf::View &pl, sf::View &pl2)
{
	window.setView(pl);
	window.draw(background);
	window.draw(mapRect);

	sf::Text coord;
	coord.setString(std::to_string(sf::Mouse::getPosition(window).x) + ", " + std::to_string(sf::Mouse::getPosition(window).y));
	coord.setFont(font);
	
	sf::Text colony;
	colony.setString("Year: " +std::to_string(resource::year));
	colony.setFont(font);
	colony.setFillColor(sf::Color::Red);
	colony.setPosition(200, 0);

	sf::Text colonyMembers;
	colonyMembers.setString("Members: " + std::to_string(colonies[0].populationSize));
	colonyMembers.setFont(font);
	colonyMembers.setFillColor(sf::Color::Red);
	colonyMembers.setPosition(500, 0);

	coord.setFillColor(sf::Color::Red);
	coord.setPosition(0, 0);
	window.setView(pl2);
	window.draw(coord);
	window.draw(colony);
	window.draw(colonyMembers);
	window.setView(pl);
}

Map::Map()
{
	
	loadMap(worldImage, resource::filename);
	worldImagebuffer = worldImage;
	worldTexture.loadFromImage(worldImage);
	loadFont(font);

	mapRect.setTexture(&worldTexture);
	mapRect.setSize(sf::Vector2f(worldImage.getSize().x, worldImage.getSize().y));


	background.setPosition(sf::Vector2f(0 - resource::ScreenWidth,0 - resource::ScreenHeight));
	background.setSize(sf::Vector2f(resource::ScreenWidth * 4, resource::ScreenHeight * 4));
	background.setFillColor(worldImage.getPixel(2,2));
	setDefaultColor(worldImage);
	
}

void Map::UpdateTexture()
{
	worldTexture.loadFromImage(worldImage);
}



void Map::AddColony(sf::Vector2f pos)
{
	if (isFree(pos))
	{
		Colony *col = new Colony(coloniesCount, pos);
		colonies.push_back(*col);
	}
}

bool Map::isWater(sf::Vector2f pos)
{
	return(worldImage.getPixel(pos.x, pos.y).b > 250);
}

bool Map::isFree(sf::Vector2f pos)
{
	return(worldImage.getPixel(pos.x, pos.y).g > 250);
}

void Map::UpdateColonies()
{
	for (int i = 0; i < colonies.size(); i++)
	{
		colonies[i].updateColony(worldImage);
	}
	UpdateTexture();
}