#include "Figure.h"
#include "Game_Board.h"
#include "Cheker.h"
#include "Crown.h"
#include <iostream>
#include <stdio.h>
#include <cassert>
std::pair<int, int> Game_Board::get_coor(const std::string& text)
{
	std::pair<int, int> coor;
	coor.first = 0;
	coor.second = 0;
	bool garb = false;
	size_t position = text.size();
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			if (garb)
			{
				position = i;
				break;
			}
			std::string s(1, text[i]);
			coor.first = 10 * coor.first + std::stoi(s);
		}
		else
		{
			garb = true;
			garbage.push_back(text[i]);
		}
	}
	for (size_t i = position; i < text.size(); i++)
	{
		if (text[i] >= '0' && text[i]<= '9')
		{
			std::string s(1, text[i]);
			coor.second = 10 * coor.second + std::stoi(s);
		}
		else
		{
			return { -1, -1 };
		}
	}
	return coor;
}
Game_Board::Game_Board(const std::string& size)
{
	auto l = get_coor(size);
	std::pair<int, int> error = { -1, -1 };
	if (l == error)
	{
		std::cout << "Invalid size";
		std::abort();
	}
	size1 = l.first;
	size2 = l.second;
	board = new Figure * *[size1];
	for (int i = 0; i < size1; i++)
	{
		board[i] = new Figure * [size2];
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			bool fvar = i % 2 == 0 && j % 2 == 0, svar = i % 2 == 1 && j % 2 == 1, vars = (fvar || svar);
			if (vars && i < size1 / 2 - 1)
			{
				board[i][j] = new Cheker(Type::BLACK, i, j);
			}
			else if (i < size1 / 2 + 1 && vars)
			{
				board[i][j] = new Cheker(Type::NOTHING, i, j);
			}
			else if (vars)
			{
				board[i][j] = new Cheker(Type::WHITE, i, j);
			}
			else
			{
				board[i][j] = new Cheker(Type::IMPOSSIBLE, i, j);
			}
		}
	}
}

void Game_Board::print_board()
{
	printf("   ");
	for (int i = 1; i <= size1; i++)
	{
		printf(" %2d", i);
	}
	printf("\n");
	int line = 0;
	for (int i = 0; i < size1; i++)
	{
		printf(" %2d", ++line);
		for (int j = 0; j < size2; j++)
		{
			if (board[i][j]->get_color() == Type::BLACK)
			{
				printf("  b");
			}
			else if (board[i][j]->get_color() == Type::WHITE)
			{
				printf("  w");
			}
			else 
			{
				printf("   ");
			}
		}
		printf("\n\n");
	}
}

void Game_Board::choose_figure(const std::string& coor)
{
	auto p = get_coor(coor);
	if (p.first > size1 || p.first <= 0 || p.second > size2 || p.second <= 0)
	{
		std::cout << "Incorrect step, another player walk" << std::endl;
		g.change_pl();
		return;
	}
	bool for_white = (g.get_pl() == Step::FIRSTPLAYER) && (board[p.first - 1][p.second - 1]->get_color() == Type::WHITE);
	bool for_black = (g.get_pl() == Step::SECONDPLAYER) && (board[p.first - 1][p.second - 1]->get_color() == Type::BLACK);
	if (for_white || for_black)
	{
		board[p.first - 1][p.second - 1]->set_pl(g.get_pl());
		int n_coor_x, n_coor_y;
		std::cin >> n_coor_x >> n_coor_y;
		std::pair<int, int> new_coor = board[p.first - 1][p.second - 1]->step(board, n_coor_x, n_coor_y);
		if (new_coor.first == -100 )
		{
			std::cout << "Incorrect step, another player walk" << std::endl;
			g.change_pl();
			return;
		}
		else
		{
			g.change_pl();
			if (new_coor.first < 0)
			{
				board[n_coor_x - 1][n_coor_y - 1]->set_type(Type::NOTHING);
				if (new_coor.first == -11)
				{
					set_figure(0, new_coor.second, p.first - 1, p.second - 1);
					return;
				}
				else
				{
					set_figure(-new_coor.first, new_coor.second, p.first - 1, p.second - 1);
					return;
				}
			}
			set_figure(new_coor.first, new_coor.second, p.first - 1, p.second - 1);
		}
	}
	else
	{
		g.change_pl();
		std::cout << "Incorrect step, another player walk" << std::endl;
		return;
	}
}

void Game_Board::set_figure(const int& x, const int& y, const int& old_x, const int& old_y)
{
	Figure* f = board[x][y];
	board[x][y] = board[old_x][old_y];
	board[old_x][old_y] = f;
	board[x][y]->set_coor(x, y);
}

Step Game_Board::get_pl()
{
	return g.get_pl();
}