#pragma once
#include <fstream>
#include <vector>

class MapGen
{
private:
	std::ifstream tilefile;
	sf::Texture tilesTexture;
	sf::Sprite tiles;
	std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;
public:
	MapGen();
	~MapGen();
	void loadMap();
	void drawMap();
};

