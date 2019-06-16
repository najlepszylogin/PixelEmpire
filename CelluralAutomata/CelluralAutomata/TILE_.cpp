#include "Map.h"

Tile::Tile(int i, int j)
{
	coords.x = i;
	coords.y = j;
	pos1.x = i * 16;
	pos1.y = j * 16;
}

void Tile::SetType(std::string type_)
{
	type = type_;
}

void Tile::Focus(sf::RenderWindow& window)
{
	focusershape.setPosition(pos1);
	window.draw(focusershape);
}