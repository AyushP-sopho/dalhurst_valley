#include <SFML\Graphics.hpp>
#include "State_Splash.h"
#include "common.h"
#include "Menu.h"
#include <iostream>


State_Splash::State_Splash()
{
	menu = new Menu(900, 400, 500);

	texLogo.loadFromFile("assets/images/logo-600x300.jpg");

	sprLogo.setTexture(texLogo);
	sprLogo.setPosition(660, 150);

	texBackground[0].loadFromFile("assets/images/test_bg_1.jpg");
	texBackground[1].loadFromFile("assets/images/test_bg_2.jpg");
	texBackground[2].loadFromFile("assets/images/test_bg_3.jpg");

	sprBackground[0].setTexture(texBackground[0]);
	sprBackground[1].setTexture(texBackground[1]);
	sprBackground[2].setTexture(texBackground[2]);

	i = 0;
	alpha1 = 0;
	alpha2 = 0;

}


State_Splash::~State_Splash()
{

}

void State_Splash::handle_events()
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
			switch (event.key.code) {
			case sf::Keyboard::Up:
				menu->MoveUp();
				break;
			case sf::Keyboard::Down:
				menu->MoveDown();
				break;
			case sf::Keyboard::Return:
				switch (menu->getPressedItem()) {
				case 0:
					set_next_state(LEVEL_0);
					break;
				case 1:
					set_next_state(STATE_ABOUT);
					break;
				case 2:
					window.close();
					break;
				}
			}
		}
	}
}

void State_Splash::logic()
{
	//No logic in state
}

void State_Splash::render()
{



	sf::Time time = clock.getElapsedTime();
	sprBackground[i].setColor(sf::Color(255, 255, 255, 255));
	sprBackground[(i + 1) % 3].setColor(sf::Color(255, 255, 255, 0));

	if (time.asSeconds() <= 3)
	{
		window.draw(sprBackground[i]);
	}
	if (time.asSeconds() > 3 && time.asSeconds() <= 3.5)
	{
		alpha1 = (3.5 - time.asSeconds()) * 255 / 0.5;
		alpha2 = 255 - alpha1;
		sprBackground[i].setColor(sf::Color(255, 255, 255, alpha1));
		sprBackground[(i + 1) % 3].setColor(sf::Color(255, 255, 255, alpha2));
		window.draw(sprBackground[i]);
		window.draw(sprBackground[(i + 1) % 3]);
	}
	if (time.asSeconds() > 3.5)
	{
		sprBackground[(i + 1) % 3].setColor(sf::Color(255, 255, 255, 255));
		window.draw(sprBackground[(i + 1) % 3]);
		i = (i + 1) % 3;
		clock.restart().asSeconds();
	}

	window.draw(sprLogo);

	menu->draw(window);

}
