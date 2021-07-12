#pragma once
#include <string>
#include "Game.h"
class Figure;
class Game_Board
{
public:
	Game_Board(const std::string& size);
	void print_board();
	void choose_figure(const std::string& coor);
	void set_figure(const int& x, const int& y, const int& old_x, const int& old_y);
	Step get_pl();
private:
	std::pair<int, int> get_coor(const std::string& size);
	Figure*** board;
	int size1 = 0, size2 = 0;
	std::string garbage;
	Game g;
};

 