#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Hero.h"

extern enum GameStates
{
	STATE_NULL,
	STATE_INTRO,
	STATE_SPLASH,
	STATE_NAME,
	STATE_ABOUT,
	STATE_EXIT,
	STATE_QUIT,
	LEVEL_0,
};

extern int stateID;
extern int nextState;

extern GameState *currentState;

extern void set_next_state(int newState);

extern void change_state();

extern sf::RenderWindow window;

extern Hero *hero;
