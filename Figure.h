#pragma once
#include <string>
#include "Game.h"
enum class Type
{
	WHITE,
	BLACK,
	NOTHING,
	IMPOSSIBLE
};
class Figure
{
public:
	Figure(Type col ,const int& x, const int& y)
		:col(col), coor_x(x), coor_y(y){}
	Type get_color();
	std::pair<int, int> get_pos();
	std::pair<int, int> step(Figure*** board, const int& n_coor_x, const int& n_coor_y);
	void set_coor(const int& x, const int& y);
	virtual std::pair<int, int> correct_step(const int& x, const int& y, Figure*** board) = 0;
	void set_type(const Type& t);
	void set_pl(const Step& s);
protected:
	Game g;
	bool defited = false;
	int coor_x, coor_y;
	Type col;
};

