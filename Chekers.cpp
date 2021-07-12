#include <iostream>
#include "Figure.h"
#include "Game_Board.h"
#include <conio.h>
int main()
{
	Game_Board g("8X8");
	g.print_board();
	std::string s;
	while (true)
	{
		std::string s;
		s = _getch();
		system("CLS");
		g.print_board();
		std::cin >> s;
		g.choose_figure(s);
	}
}
