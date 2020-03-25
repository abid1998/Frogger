#ifndef GAME_H
#define GAME_H

#include <vector>
#include <conio.h>
#include <Windows.h>

#include "lane.hpp"
#include "player.hpp"

class game
{
private:
	bool quit;
	int number_of_lanes;
	int width;
	int score = 0;
	player *player1;
	std::vector<lane *> mp;
public:
	game(int , int );
	~game();
	void draw();
	void input();
	void logic();
	void run();
};
#endif
