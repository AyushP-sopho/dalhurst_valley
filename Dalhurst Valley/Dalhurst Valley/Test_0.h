#pragma once
#include "GameState.h"
#include "MapGen.h"

class Test_0 :
	public GameState
{
private:
	MapGen *map;
public:
	Test_0();
	~Test_0();
	void handle_events();
	void logic();
	void render();
};

