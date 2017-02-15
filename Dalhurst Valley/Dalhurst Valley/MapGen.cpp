#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include "MapGen.h"
#include "common.h"



MapGen::MapGen()
{
	tilefile.open("assets/maps/map1.txt");
}


MapGen::~MapGen()
{
}

void MapGen::loadMap()
{
	if (tilefile.is_open())
	{
		std::string tileLocation;
		tilefile >> tileLocation;
		tilesTexture.loadFromFile(tileLocation);
		while (!tilefile.eof())
		{
			std::string str;
			tilefile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
				tempMap.push_back(sf::Vector2i(-1, -1));
			else
				tempMap.push_back(sf::Vector2i(x - '0', y - '0'));
			if (tilefile.peek() == '\n')
			{
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
		map.push_back(tempMap);
	}
	tiles.setTexture(tilesTexture);

}

void MapGen::drawMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tiles.setPosition(j * 100, i * 100);
				tiles.setTextureRect(sf::IntRect(map[i][j].x  * 100, map[i][j].y * 100, 100, 100));
				window.draw(tiles);

			}
		}
	}
}

