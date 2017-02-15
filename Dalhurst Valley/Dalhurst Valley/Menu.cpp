#include "Menu.h"



Menu::Menu(float x, float y, float height)
{
	font.loadFromFile("assets/fonts/Ragnarok.ttf");
	txtList[0].setFont(font);
	txtList[0].setString("Play");
	txtList[0].setColor(sf::Color(50, 50, 50));
	txtList[0].setPosition(sf::Vector2f(x, y + height / (MAX_NUM_OF_ITEMS + 1) * 1));

	txtList[1].setFont(font);
	txtList[1].setString("About");
	txtList[1].setColor(sf::Color::White);
	txtList[1].setPosition(sf::Vector2f(x, y + height / (MAX_NUM_OF_ITEMS + 1) * 2));

	txtList[2].setFont(font);
	txtList[2].setString("Exit");
	txtList[2].setColor(sf::Color::White);
	txtList[2].setPosition(sf::Vector2f(x, y + height / (MAX_NUM_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUM_OF_ITEMS; i++) {
		window.draw(txtList[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		txtList[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		txtList[selectedItemIndex].setColor(sf::Color(50, 50, 50));

	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUM_OF_ITEMS) {
		txtList[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		txtList[selectedItemIndex].setColor(sf::Color(50, 50, 50));
	}
}

int Menu::getPressedItem()
{
	return selectedItemIndex;
}