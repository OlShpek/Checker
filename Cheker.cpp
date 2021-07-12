#include "Cheker.h"
#include <cmath>
std::pair<int, int> Cheker::correct_step(const int& x, const int& y, Figure*** board)
{
	if (g.get_pl() == Step::FIRSTPLAYER)
	{
		bool reg_step = board[x][y]->get_color() == Type::NOTHING && std::abs(y - coor_y) == 1 && (x - coor_x) == -1;
		int a = x - coor_x;
		if (reg_step)
		{

			return { 10, 10 };
		}
		if (x - 1 >= 0 && y - 1 >= 0)
		{
			bool beat = (x < coor_x) && (y < coor_y) && (board[x][y]->get_color() == Type::BLACK) && board[x - 1][y - 1]->get_color() == Type::NOTHING;
			if (beat)
			{
				if (x - 1 == 0)
				{
					return { -11, y - 1 };
				}
				return { -(x - 1), y - 1 };
			}
		}
		if (x - 1 >= 0 && y + 1 < 8)
		{
			bool beat = (x < coor_x) && (y > coor_y) && (board[x][y]->get_color() == Type::BLACK) && (board[x - 1][y + 1]->get_color() == Type::NOTHING);
			if (beat)
			{
				if (x - 1 == 0)
				{
					return { -11, y - 1 };
				}
				return { -(x - 1), y + 1 };
			}
		}
		if (x + 1 < 8 && y - 1 >= 0)
		{
			bool beat = (x > coor_x) && (y < coor_y) && (board[x][y]->get_color() == Type::BLACK) && (board[x + 1][y - 1]->get_color() == Type::NOTHING);
			if (beat)
			{
				return { -(x + 1), y - 1 };
			}
		}
		if (x + 1 < 8 && y + 1 < 8)
		{
			bool beat = (x > coor_x) && (y > coor_y) && (board[x][y]->get_color() == Type::BLACK) && (board[x + 1][y + 1]->get_color() == Type::NOTHING);
			if (beat) 
			{
				return { -(x + 1), y + 1 };
			}
		}
	}
	else
	{
		bool reg_step = board[x][y]->get_color() == Type::NOTHING && std::abs(y - coor_y) == 1 && (x - coor_x) == 1;
		if (reg_step)
		{
			return { 10, 10 };
		}
		if (x - 1 >= 0 && y - 1 >= 0)
		{
			bool beat = (x < coor_x) && (y < coor_y) && (board[x][y]->get_color() == Type::WHITE) && board[x - 1][y - 1]->get_color() == Type::NOTHING;
			if (beat)
			{
				if (x - 1 == 0)
				{
					return { -11, y + 1 };
				}
				return { -(x - 1) , y - 1 };
			}
		}
		if (x - 1 >= 0 && y + 1 < 8)
		{
			bool beat = (x < coor_x) && (y > coor_y) && (board[x][y]->get_color() == Type::WHITE) && (board[x - 1][y + 1]->get_color() == Type::NOTHING);
			if (beat)
			{
				if (x - 1 == 0)
				{
					return { -11, y + 1 };
				}
				return { -(x - 1), y + 1 };
			}
		}
		if (x + 1 < 8 && y - 1 >= 0)
		{
			bool beat = (x > coor_x) && (y < coor_y) && (board[x][y]->get_color() == Type::WHITE) && (board[x + 1][y - 1]->get_color() == Type::NOTHING);
			if (beat)
			{
				return { -(x + 1), y - 1 };
			}
		}
		if (x + 1 < 8 && y + 1 < 8)
		{
			bool beat = (x > coor_x) && (y > coor_y) && (board[x][y]->get_color() == Type::WHITE) && (board[x + 1][y + 1]->get_color() == Type::NOTHING);
			if (beat)
			{
				return { -(x + 1), y + 1 };
			}
		}
	}
	return { -100, -100 };
}