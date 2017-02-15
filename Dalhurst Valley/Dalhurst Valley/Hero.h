#pragma once
#include <SFML/Graphics.hpp>


class Hero
{
private:
	enum direction {DOWN, UP, LEFT, RIGHT};
	int max_health;
	int xp;
	sf::Texture texSheet;
	sf::Sprite sprSheet;
	sf::Vector2i source;
	sf::Clock walkClock;
	float speed;

public:
	Hero();
	~Hero();
	void setSpawnPoint(sf::Vector2f postion);
	void orient(int direction);
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	void drawHero();
};