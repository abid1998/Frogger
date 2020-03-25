#include<iostream>
#include "game.hpp"

using namespace std;

int main()
{
	game g1(50, 20);
	system("cls");
	g1.run();
	cout << "Game over";
	getchar();
	return 0;
}
