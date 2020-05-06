#include "Controller.h"
#include "Server.h"
#include "Customer.h"
#include "Animation.h"
#include <iostream>
using namespace std;

struct Room
{
	string name;
	bool is_reserved = false;
	int type = 0;
	bool is_serviced = false;
	float charge = 1000;
};

int main()
{
	Controller my_menu;
	Animation::main_animation();
	my_menu.main_menu();

	return 0;
}

