#include <SFML/Graphics.hpp>
#include "Test_0.h"
#include "MapGen.h"
#include "common.h"



Test_0::Test_0()
{
	hero = new Hero();
	map = new MapGen();
	map->loadMap();
	hero->setSpawnPoint(sf::Vector2f(100, 50));
}


Test_0::~Test_0()
{
}


void Test_0::handle_events()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				hero->orient(1);
				hero->moveUp();
				break;
			case sf::Keyboard::A:
				hero->orient(2);
				hero->moveLeft();
				break;
			case sf::Keyboard::S:
				hero->orient(0);
				hero->moveDown();
				break;
			case sf::Keyboard::D:
				hero->orient(3);
				hero->moveRight();
				break;

			}

		}
	}
}

void Test_0::logic()
{

}

void Test_0::render()
{
	map->drawMap();
	hero->drawHero();
}