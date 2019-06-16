#pragma once


#include "WorkManager.h"



#ifndef TILE__
#define TILE__



class Tile 
{
private:
	sf::Vector2i coords;
	std::string type;
	std::string undertype;
	bool focused = false;


public:
	Tile(int i, int j);
	void SetType(std::string type_);
	sf::Vector2f pos1;
	void Focus(sf::RenderWindow& window);
	std::string getType()
	{
		return type;
	}
	std::string getUndertype()
	{
		return undertype;
	}
	void SetUndertype(std::string type_)
	{
		undertype = type_;
	}
};


#endif TILE__

#ifndef MAP__
#define MAP__


class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	std::vector <std::vector<Tile>> maptile;


	bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height)
	{
		// load the tileset texture
		if (!m_tileset.loadFromFile(tileset))
			return false;
		// load the tileset texture
		if (!m_borders.loadFromFile("Assets/Tiles/borders.png"))
			return false;


		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);
		m_vertices2.setPrimitiveType(sf::Quads);
		m_vertices2.resize(width * height * 4);



		for (int i = 0; i < height; i++)
		{
			std::vector<Tile> row;
			maptile.push_back(row);

			for (int j = 0; j < width ; j++)
			{
				Tile* buff = new Tile(i, j);
				maptile[i].push_back(*buff);
				delete buff;

			}
		}



		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < height; ++i)
			for (unsigned int j = 0; j < width; ++j)
			{
				// get the current tile number

				int tileNumber = 0;
				int land = 0;



				if (worldImg.getPixel(i, j).g == 255)
				{
					land = 0;
					tileNumber = rand()%2;
					maptile[i][j].SetType("grass");
					sf::Color recolour = worldImg.getPixel(i, j);
					recolour.g -= tileNumber;
					worldImg.setPixel(i, j, recolour);
				}
				if (worldImg.getPixel(i, j).g == 100)
				{
					land = 3;
					tileNumber = 8 + rand() % 2 * 19;
					maptile[i][j].SetType("pine_forest");
					sf::Color recolour = worldImg.getPixel(i, j);
					recolour.g -= tileNumber;
					worldImg.setPixel(i, j, recolour);


					if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
					{

						
						//normals
						if (worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 0 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 2 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 3 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 1 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 6 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 7 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 4 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 5 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;

						}
						//vert and hor corridors
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 18 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						if (worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 17 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						//bends
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 13 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 12 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 14 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 15 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 3;
							tileNumber = 16 + rand() % 2 * 19;
							maptile[i][j].SetType("pine_forest");
							recolour.g -= tileNumber;
							
						}

						worldImg.setPixel(i, j, recolour);
					}
				}

				if (worldImg.getPixel(i, j).g == 125 && worldImg.getPixel(i, j).b == 125 && worldImg.getPixel(i, j).r == 125)
				{
					land = 4;
					tileNumber = rand() % 2;
					maptile[i][j].SetType("mountains");
					sf::Color recolour = worldImg.getPixel(i, j);
					recolour.g -= tileNumber;
					worldImg.setPixel(i, j, recolour);
				}
				if (worldImg.getPixel(i, j).g == 100)
				{
					land = 4;
					tileNumber = 8 + rand() % 2 * 19;
					maptile[i][j].SetType("mountains");
					sf::Color recolour = worldImg.getPixel(i, j);
					recolour.g -= tileNumber;
					worldImg.setPixel(i, j, recolour);


					if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
					{


						//normals
						if (worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 0 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 2 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 3 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;


						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 1 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 6 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 7 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 4 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 5 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						//vert and hor corridors
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 18 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 17 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						//bends
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 13 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 12 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 14 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 125;
							land = 4;
							tileNumber = 15 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}
						if (worldImg.getPixel(i + 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j - 1).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i - 1, j).g != worldImg.getPixel(i, j).g && worldImg.getPixel(i, j + 1).g != worldImg.getPixel(i, j).g)
						{
							recolour.g = 100;
							land = 4;
							tileNumber = 16 + rand() % 2 * 19;
							maptile[i][j].SetType("mountains");
							recolour.g -= tileNumber;

						}

						worldImg.setPixel(i, j, recolour);
					}
				}


				if (worldImg.getPixel(i, j).b == 255)
				{
					sf::Color recolour = worldImg.getPixel(i, j);
					land = 1;
					tileNumber = rand()%2;	
					maptile[i][j].SetType("water");
					

					//coast
					if (i > 0 && j > 0 && i < height-1 && j < width-1)
					{
						//corners
						if (worldImg.getPixel(i + 1, j + 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 10;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i - 1, j - 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 8;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i- 1, j + 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 11;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i + 1, j - 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 9;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						//normals
						if (worldImg.getPixel(i, j-1).b  < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 0;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;

						}
						if (worldImg.getPixel(i-1, j).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 2;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;

						}
						if (worldImg.getPixel(i , j+1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 3;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;

						}
						if (worldImg.getPixel(i+1, j).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 1;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						//inner corners
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j+1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 6;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i - 1, j).b < 240 && worldImg.getPixel(i, j + 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 7;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i - 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 4;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 5;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						//vertical and horizontal water
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i - 1, j).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 18;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i, j + 1).b < 240 && worldImg.getPixel(i, j - 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 17;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						//inner bends
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240 && worldImg.getPixel(i -1, j ).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 13;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240 && worldImg.getPixel(i, j+1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 12;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j + 1).b < 240 && worldImg.getPixel(i - 1, j).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 14;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i - 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240 && worldImg.getPixel(i, j+1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 15;
							maptile[i][j].SetType("coast");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						if (worldImg.getPixel(i + 1, j).b < 240 && worldImg.getPixel(i, j - 1).b < 240 && worldImg.getPixel(i - 1, j).b < 240 && worldImg.getPixel(i, j + 1).b < 240)
						{
							recolour.g = 0;
							recolour.b = 255;
							land = 2;
							tileNumber = 16;
							maptile[i][j].SetType("lake");
							recolour.g += tileNumber;
							recolour.b -= 10;
						}
						

					}
					if (maptile[i][j].getType() == "water")
					{
						recolour.b = 255;
						recolour.b -= tileNumber;
					}
					worldImg.setPixel(i, j, recolour);
				}
				if (empires.getPixel(i, j).g != 255 && empires.getPixel(i, j).r != 255 && empires.getPixel(i, j).b != 255)
				{
					sf::Sprite buff;
					buff.setTexture(m_borders);
					buff.setColor(empires.getPixel(i, j));
					std::cout << buff.getColor().r;
					m_borders.update(*buff.getTexture());

					
					
				}
			
				

				// find its position in the tileset texture
				int tu = tileNumber % ((m_tileset.getSize().x / tileSize.x) + land);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x) + land;

				// get a pointer to the current tile's quad
				sf::Vertex * quad = &m_vertices[(i + j * height) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

				
			}




				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
					{

					
						if (worldImg.getPixel(i, j).g >= 245)maptile[i][j].SetType("grass");
						if (worldImg.getPixel(i, j).b >= 245)maptile[i][j].SetType("water");
						if (worldImg.getPixel(i, j).b == 245 && worldImg.getPixel(i, j).g >= 0)maptile[i][j].SetType("coast");
						if (worldImg.getPixel(i, j).g <= 100 && worldImg.getPixel(i, j).g >= 50)maptile[i][j].SetType("pine_forest");
						if (worldImg.getPixel(i, j).g <= 125 && worldImg.getPixel(i, j).b == 125 && worldImg.getPixel(i, j).r == 125)maptile[i][j].SetType("mountains");
						if (i >= 0 && j >= 0 && i < height && j < width)
						{
						
							if (maptile[i][j].getType() == "pine_forest")
							{
								int number = (100 - worldImg.getPixel(i, j).g) / 19;
								int tileNumber = 8;
								int land = 3;

								sf::Color recolour = worldImg.getPixel(i, j);
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
								recolour.b = 0;
								recolour.r = 0;
								worldImg.setPixel(i, j, recolour);

								if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
								{


									//normals
									if (maptile[i][j - 1].getType() != "pine_forest")
									{
										land = 3;
										tileNumber = 0;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i - 1][j].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 2;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 3;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i + 1][j].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 1;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 6;
										recolour.g = 100;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 7;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 4;
										recolour.g = 100;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 5;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									//vert and hor corridors
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 18;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i][j + 1].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 17;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									//bends
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 13;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 12;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 14;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 15;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
									{

										land = 3;
										tileNumber = 16;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}

									worldImg.setPixel(i, j, recolour);



								}

							}

							if (maptile[i][j].getType() == "mountains")
							{
								int number = (100 - worldImg.getPixel(i, j).g) / 19;
								int tileNumber = 8;
								int land = 4;

								sf::Color recolour = worldImg.getPixel(i, j);
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
								recolour.b = 125;
								recolour.r = 125;
								worldImg.setPixel(i, j, recolour);

								if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
								{


									//normals
									if (maptile[i][j - 1].getType() != "mountains")
									{
										land = 4;
										tileNumber = 0;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i - 1][j].getType() != "mountains")
									{

										land = 4;
										tileNumber = 2;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 3;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;
									}
									if (maptile[i + 1][j].getType() != "mountains")
									{

										land = 4;
										tileNumber = 1;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 6;
										recolour.g = 100;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 7;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 4;
										recolour.g = 100;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 5;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									//vert and hor corridors
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
									{

										land = 4;
										tileNumber = 18;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i][j + 1].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 17;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									//bends
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
									{

										land = 4;
										tileNumber = 13;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 12;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
									{

										land = 4;
										tileNumber = 14;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 15;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}
									if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
									{

										land = 4;
										tileNumber = 16;
										recolour.g = 100;
										if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
										recolour.g -= tileNumber;

									}

									worldImg.setPixel(i, j, recolour);
								}


							}

						}
						else continue;
					}
				}
			

		return true;
	}

	bool UpdateMap2(sf::Vector2u tileSize, unsigned int width, unsigned int height, sf::View& cam, sf::Color empireColor)
	{
		
		for (unsigned int i = 0; i < height; ++i)
			for (unsigned int j = 0; j < width; j++)
			{
				if (i <= 0 || j <= 0 || i >= height || j >= width)continue;
				int tileNumber = 0;

				
				if (empires.getPixel(i, j).g != 255 && empires.getPixel(i, j).r != 255 && empires.getPixel(i, j).b != 255)
				{


					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r != empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r != empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r != empires.getPixel(i, j).r)
					{

						tileNumber = 8;
					}


					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r != empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r != empires.getPixel(i, j).r)
					{
						tileNumber = 9;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r != empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r != empires.getPixel(i, j).r)
					{
						tileNumber = 10;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r != empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r != empires.getPixel(i, j).r)
					{
						tileNumber = 11;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r != empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r != empires.getPixel(i, j).r)
					{
						tileNumber = 12;
					}

					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 0;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 5;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 6;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 7;
					}
					//////
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r != empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r != empires.getPixel(i, j).r)
					{
						tileNumber = 13;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r != empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r != empires.getPixel(i, j).r)
					{
						tileNumber = 14;
					}
					/////////////
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 1;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 2;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 3;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 4;
					}
					if (empires.getPixel(i, j).r != 255 && empires.getPixel(i - 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i + 1, j).r == empires.getPixel(i, j).r && empires.getPixel(i, j + 1).r == empires.getPixel(i, j).r && empires.getPixel(i, j - 1).r == empires.getPixel(i, j).r)
					{
						tileNumber = 15;
					}




					int land = 255 - empires.getPixel(i, j).r;
					// find its position in the tileset texture
					int tu = tileNumber % ((m_borders.getSize().x / tileSize.x) + land);
					int tv = tileNumber / (m_borders.getSize().x / tileSize.x) + land;

					// get a pointer to the current tile's quad
					sf::Vertex * quad2 = &m_vertices2[(i + j * height) * 4];

					// define its 4 corners
					quad2[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad2[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad2[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad2[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					// define its 4 texture coordinates
					quad2[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
					quad2[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
					quad2[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
					quad2[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
				}
		
				
				
					
				

			}

		return true;
	}

	void Update(sf::Vector2f pos , sf::Vector2u tileSize)
	{
		if (pos.x >= 0 && pos.y >= 0 && pos.x < width && pos.y < height)
		{
			if (worldImg.getPixel(pos.x, pos.y).g >= 245)maptile[pos.x][pos.y].SetType("grass");
			if (worldImg.getPixel(pos.x, pos.y).b >= 245)maptile[pos.x][pos.y].SetType("water");
			if (worldImg.getPixel(pos.x, pos.y).b == 245 && worldImg.getPixel(pos.x, pos.y).g >= 0)maptile[pos.x][pos.y].SetType("coast");
			if (worldImg.getPixel(pos.x, pos.y).g <= 100 && worldImg.getPixel(pos.x,pos.y).g>=50)maptile[pos.x][pos.y].SetType("pine_forest");
			if (worldImg.getPixel(pos.x, pos.y).g <= 125 && worldImg.getPixel(pos.x, pos.y).b == 125 && worldImg.getPixel(pos.x, pos.y).r == 125)maptile[pos.x][pos.y].SetType("mountains");
			
		}

	for (int i = pos.x - 1; i <= pos.x + 1; i++)
		{
			for (int j = pos.y - 1; j <= pos.y + 1; j++)
			{
				if(i>=0 && j>=0 && i<width && j<height)
				{ 
					if (maptile[i][j].getType() == "pine_forest")
					{
						int number = (100 - worldImg.getPixel(i, j).g) / 19;
						int tileNumber = 8;
						int land = 3;
						
						sf::Color recolour = worldImg.getPixel(i, j);
						recolour.g = 100;
						if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
						recolour.g -= tileNumber;
						recolour.b = 0;
						recolour.r = 0;
						worldImg.setPixel(i, j, recolour);

						if (i > 0 && j > 0 && i < width - 1 && j < height - 1)
						{


							//normals
							if (maptile[i][j - 1].getType() != "pine_forest")
							{
								land = 3;
								tileNumber = 0;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i - 1][j].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 2;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 3;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i + 1][j].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 1;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 6;
								recolour.g = 100;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 7;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 4;
								recolour.g = 100;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 5;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							//vert and hor corridors
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 18;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i][j + 1].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 17;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							//bends
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 13;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 12;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 14;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 15;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "pine_forest" && maptile[i][j - 1].getType() != "pine_forest" && maptile[i - 1][j].getType() != "pine_forest" && maptile[i][j + 1].getType() != "pine_forest")
							{

								land = 3;
								tileNumber = 16;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							
							worldImg.setPixel(i, j, recolour);



						}

					}

					if (maptile[i][j].getType() == "mountains")
					{
						int number = (100 - worldImg.getPixel(i, j).g) / 19;
						int tileNumber = 8;
						int land = 4;

						sf::Color recolour = worldImg.getPixel(i, j);
						recolour.g = 100;
						if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
						recolour.g -= tileNumber;
						recolour.b = 125;
						recolour.r = 125;
						worldImg.setPixel(i, j, recolour);

						if (i > 0 && j > 0 && i < width - 1 && j < height - 1)
						{


							//normals
							if (maptile[i][j - 1].getType() != "mountains")
							{
								land = 4;
								tileNumber = 0;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i - 1][j].getType() != "mountains")
							{

								land = 4;
								tileNumber = 2;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 3;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;
							}
							if (maptile[i + 1][j].getType() != "mountains")
							{

								land = 4;
								tileNumber = 1;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 6;
								recolour.g = 100;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 7;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 4;
								recolour.g = 100;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 5;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							//vert and hor corridors
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
							{

								land = 4;
								tileNumber = 18;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i][j + 1].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 17;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							//bends
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
							{

								land = 4;
								tileNumber = 13;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 12;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains")
							{

								land = 4;
								tileNumber = 14;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i - 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 15;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}
							if (maptile[i + 1][j].getType() != "mountains" && maptile[i][j - 1].getType() != "mountains" && maptile[i - 1][j].getType() != "mountains" && maptile[i][j + 1].getType() != "mountains")
							{

								land = 4;
								tileNumber = 16;
								recolour.g = 100;
								if ((100 - worldImg.getPixel(i, j).g) % 36 > 18)tileNumber += 19;
								recolour.g -= tileNumber;

							}

							worldImg.setPixel(i, j, recolour);
						}


						}

					}
				else continue;
			}
		}
	}

	

	bool Animate(sf::Vector2u tileSize, unsigned int width, unsigned int height, sf::View &cam)
		{
			
		
			for (unsigned int i = (cam.getCenter().x - cam.getSize().x/2 )/16 ; i < cam.getCenter().x + cam.getSize().x/16; ++i)
				for (unsigned int j = (cam.getCenter().y - cam.getSize().y/2) / 16; j < cam.getCenter().y + cam.getSize().y/16; j++)
				{
					if (i < 0 || j < 0 || i >= height || j >= width)continue;
					int animation = rand() % 2;

					int tileNumber = 0;
					int land = 0;

					

					if (maptile[i][j].getType() == "grass")
					{
						land = 0;
						tileNumber = 255 - worldImg.getPixel(i, j).g + animation * 19;

					}else
					if (i > 0 && j > 0 && i < height - 1 && j < width - 1 && maptile[i][j].getType() == "pine_forest")
					{
						land = 3;
						tileNumber = 100 - worldImg.getPixel(i, j).g;

					}else
					if (i > 0 && j > 0 && i < height - 1 && j < width - 1 && maptile[i][j].getType() == "mountains")
					{
						land = 4;
						tileNumber = 100 - worldImg.getPixel(i, j).g;
					}
					else
					if (maptile[i][j].getType() == "water")
					{

						land = 1;
						tileNumber = 255 - worldImg.getPixel(i, j).b + animation * 19;

					}
					else
						if (i > 0 && j > 0 && i < height - 1 && j < width - 1 && (maptile[i][j].getType() == "coast" || maptile[i][j].getType() == "lake"))
						{
							land = 2;
							tileNumber = worldImg.getPixel(i, j).g + animation * 19;

						}

						else continue;





					// find its position in the tileset texture
					int tu = tileNumber % ((m_tileset.getSize().x / tileSize.x) + land);
					int tv = tileNumber / (m_tileset.getSize().x / tileSize.x) + land;

					// get a pointer to the current tile's quad
					sf::Vertex * quad = &m_vertices[(i + j * height) * 4];

					// define its 4 corners
					quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					// define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
					quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
					quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
					quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
					
					
					
				}

			return true;
		
	}

	std::string getTileType(int x, int y)
	{
		return maptile[x][y].getType();
	}
	

private:

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
		
		
		states.texture = &m_borders;

		// draw the vertex array
		target.draw(m_vertices2, states);

		
	}
	

	sf::VertexArray m_vertices;
	sf::VertexArray m_vertices2;
	sf::Texture m_tileset;
	sf::Texture m_borders;
	
	
};


#endif MAP__
