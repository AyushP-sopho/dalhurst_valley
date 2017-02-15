#include "Hero.h"
#include "common.h"


Hero::Hero()
{
	texSheet.loadFromFile("assets/images/test_spr_sheet.png");
	sprSheet.setTexture(texSheet);
	source.x = 0;
	source.y = DOWN;
	speed = 30;

}


Hero::~Hero()
{
}

void Hero::setSpawnPoint(sf::Vector2f position)
{
	sprSheet.setPosition(position);
}

void Hero::orient(int direction)
{
	source.y = direction;
	sf::Time time = walkClock.getElapsedTime();
	if (time.asSeconds() > 0.01)
	{
		source.x = (source.x + 1) % 4;
		walkClock.restart().asSeconds();
	}
}

void Hero::moveUp()
{
	sprSheet.setPosition(sprSheet.getPosition().x, sprSheet.getPosition().y - speed);
}

void Hero::moveRight()
{
	sprSheet.setPosition(sprSheet.getPosition().x + speed, sprSheet.getPosition().y);
}

void Hero::moveDown()
{
	sprSheet.setPosition(sprSheet.getPosition().x, sprSheet.getPosition().y + speed);
}

void Hero::moveLeft()
{
	sprSheet.setPosition(sprSheet.getPosition().x - speed, sprSheet.getPosition().y);
}

void Hero::drawHero()
{
	sprSheet.setTextureRect(sf::IntRect(source.x * 100, source.y * 150, 100, 150));
	window.draw(sprSheet);
}