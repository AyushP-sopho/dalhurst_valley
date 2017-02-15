#pragma once
#include "GameState.h"


class State_Intro :
	public GameState
{
private:
	sf::Font font;
	sf::Text txtCourse;
	sf::Texture texLogo, texBackground;
	sf::Sprite sprLogo, sprBackground;
	sf::Clock clock;

public:
	State_Intro();
	~State_Intro();
	void handle_events();
	void logic();
	void render();
};

