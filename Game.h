#pragma once

enum class Step
{
	FIRSTPLAYER,
	SECONDPLAYER
};
class Game
{
public:
	Game()
		:step(Step::FIRSTPLAYER) {}
	void change_pl();
	Step get_pl();
private: 
	Step step;
};

