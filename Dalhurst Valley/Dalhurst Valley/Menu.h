#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUM_OF_ITEMS 3

class Menu
{
public:
	Menu(float x, float y, float height);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text txtList[MAX_NUM_OF_ITEMS];
};
