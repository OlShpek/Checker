#include "Game.h"



Step Game::get_pl()
{
	return step;
}

void Game::change_pl()
{
	if (step == Step::FIRSTPLAYER)
	{
		step = Step::SECONDPLAYER;
	}
	else
	{
		step = Step::FIRSTPLAYER;
	}
}

