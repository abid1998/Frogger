#include "game.hpp"

game::game(int width, int h)
{
	number_of_lanes = h;
	this->width = width;
	quit = false;
	for(int i=0; i < number_of_lanes; i++)
	{
		mp.push_back(new lane(this->width));
	}
	player1 = new player(this->width);
}

game:: ~game()
{
	delete player1;
	for(int i = 0; i < mp.size(); i++)
	{
		lane *current = mp.back();
		mp.pop_back();
		delete current;
	}
}

void game:: draw()
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;

	Position.X = 0;
	Position.Y = 0;

	SetConsoleCursorPosition(hOut, Position) ;
	for(int i=0; i < number_of_lanes; i++)
	{
		for(int j=0; j < width; j++)
		{
			if(i == 0 && (j == 0 || j == width - 1))
				std::cout << "Start";

			if(mp[i]->check_pos(j) && i != 0 && i != number_of_lanes - 1)
				std::cout << "#";
			else if(player1->x == j && player1->y == i)
				std::cout << "P";
			else
				std::cout << " ";

			if(i == number_of_lanes - 1 && (j == 0 || j == width - 1))
				 std::cout << "End";

		}
		std::cout << std::endl;
	}
	std::cout << "Score" << score << std::endl;
}
void game::input()
{
	if(_kbhit())
	{
		char curr = _getch();
		if(curr == 'a')
			player1->x--;
		if(curr == 'd')
			player1->x++;
		if(curr == 'w')
			player1->y--;
		if(curr == 's')
			player1->y++;

		if(curr == 'q')
			quit = true;
	}
}
void game::logic()
{
	for(int i=1; i < number_of_lanes - 1; i++)
	{
		if(rand() % 10 == 1)
		{
			mp[i]->move();
		}
		if(mp[i]->check_pos(player1->x) && player1->y == i)
			quit = true;

		if (player1->y == number_of_lanes - 1)
		{
			score++;
			player1->y = 0;
			std::cout << "\x07"; // To play sound
			mp[rand() % number_of_lanes]->change_direction();
		}
	}
}
void game::run()
{
	while(!quit)
	{
		input();
		draw();
		logic();
	}
}
