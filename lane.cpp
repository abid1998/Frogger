#include "lane.hpp"

lane::lane(int width)
{
	for(int i=0; i < width; i++)
	{
		vehicles.push_front(true);
	}
	right = rand() % 2;
}

void lane:: move()
{
	if(right)
	{
		if(rand() % 10 == 1)
		{
			vehicles.push_front(true);
		}
		else
		{
			vehicles.push_front(false);
		}
		vehicles.pop_back();
	} else {
		if(rand() % 10 == 1)
		{
			vehicles.push_back(true);
		}
		else
		{
			vehicles.push_back(false);
		}
		vehicles.pop_front();
	}
}

void lane:: change_direction()
{
	right = !right;
}

bool lane:: check_pos(int pos)
{
	return vehicles[pos];
}
