#pragma once
#include "GameState.h"
#include "common.h"
#include "Menu.h"

class State_Splash :
	public GameState
{
private:
	Menu* menu;
	sf::Texture texLogo, texBackground[3];
	sf::Sprite sprLogo, sprBackground[3];
	sf::Clock clock;
	int i;
	float alpha1, alpha2;

public:

	State_Splash();
	~State_Splash();
	void handle_events();
	void logic();
	void render();
};

