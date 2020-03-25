#ifndef LANE_H
#define LANE_H

#include <deque>
#include <iostream>

class lane
{
private:
	std::deque<bool> vehicles;
	bool right;

public:
	lane(int width);
	void move();
	void change_direction();
	bool check_pos(int pos);
};

#endif
