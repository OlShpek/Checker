#pragma once
#include "Figure.h"
class Cheker : public Figure
{
public:
	Cheker(Type col, const int& x, const int y)
		:Figure(col, x, y) {}
	virtual std::pair<int, int> correct_step(const int& x, const int& y, Figure*** board) override;
};