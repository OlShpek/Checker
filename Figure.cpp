#include "Figure.h"
#include <iostream>

Type Figure::get_color()
{
	return col;
}

std::pair<int, int> Figure::get_pos()
{
	return { coor_x, coor_y };
}

std::pair<int, int> Figure::step(Figure*** board, const int& n_coor_x, const int& n_coor_y)
{
	std::pair<int, int> can = correct_step(n_coor_x - 1, n_coor_y - 1, board);
	if (can.first == 10)
	{
		return { n_coor_x - 1, n_coor_y - 1 };
	}
	else if (can.first != -100)
	{
		return can;
	}
	else
	{
		return { -100, -100 };
	}
}

void Figure::set_type(const Type& t)
{
	col = t;
}

void Figure::set_coor(const int& x, const int& y)
{
	coor_x = x;
	coor_y = y;
}

void Figure::set_pl(const Step& s)
{
	if (s != g.get_pl())
	{
		g.change_pl();
	}
}