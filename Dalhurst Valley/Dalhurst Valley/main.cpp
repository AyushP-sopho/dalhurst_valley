#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "GameState.h"
#include "FrameRate.h"
#include "State_Intro.h"
#include "State_Splash.h"
#include "State_About.h"
#include "Test_0.h"
#include "common.h"

enum GameStates;

int stateID = STATE_INTRO;
int nextState = STATE_NULL;

GameState *currentState = NULL;

Hero *hero = NULL;

void set_next_state(int newState)
{
	if (nextState != STATE_EXIT)
		nextState = newState;
}


void change_state()
{
	if (nextState != STATE_NULL)
	{
		if (nextState != STATE_EXIT)
			delete currentState;
	}
	switch (nextState)
	{
	case STATE_SPLASH:
		currentState = new State_Splash();
		break;

	case STATE_ABOUT:
		currentState = new State_About();
		break;

	case LEVEL_0:
		currentState = new Test_0();
		break;

		/*case STATE_BLUE_ROOM:
		currentState = new BlueRoom();
		break;*/
	}

	stateID = nextState;

	nextState = STATE_NULL;
}

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dalhurst Valley", sf::Style::Fullscreen);



int main() {

	FrameRate *frameRate = new FrameRate();

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		currentState = new State_Intro();
		while (stateID != STATE_EXIT)
		{
			frameRate->calcFrameRate();

			currentState->handle_events();

			currentState->logic();

			change_state();

			window.clear();

			currentState->render();

			frameRate->dispFrameRate();

			window.display();
		}

	}

}