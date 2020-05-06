#include "Controller.h"
#include "Server.h"
#include "Customer.h"
#include "Animation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

Server server1;
Customer cust1;

//Program menu
void Controller::main_menu()
{
	int color_cyan = 11;
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("        WELCOME TO        ", color_cyan);
	Animation::frame_phrase("     HOTEL UZBEKISTAN!    ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("      1. Log in           ", color_cyan);
	Animation::frame_phrase("      2. About hotel      ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("      0. Exit             ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				log_in();
				break;
			case '2':
				system("cls");
				about();
				break;
			case '0':
				system("cls");
				Animation::bye();
				cin.ignore();
				exit(1);
			}
		}
	}
}

//Log in menu
void Controller::log_in()
{
	int color_cyan = 11;
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("         LOG IN:          ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("      1. Manager          ", color_cyan);
	Animation::frame_phrase("      2. Customer         ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("      0. Back             ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				server1.verification_admin();
				break;
			case '2':
				system("cls");
				cust1.verification_customer();
				break;
			case '0':
				system("cls");
				main_menu();
				break;
			}
		}
	}
}

//About program
void Controller::about()
{
	int color_cyan = 11;
	cout << endl;
	Animation::draw_border(54, color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::frame_phrase("             ABOUT HOTEL UZBEKISTAN:              ", color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::draw_border(54, color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::frame_phrase("  Hotel 'UZBEKISTAN' was built in 2012 and now is ", color_cyan);
	Animation::frame_phrase("  one of the most popular hotel in Uzbekistan     ", color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::frame_phrase("  For more detailed information:                  ", color_cyan);
	Animation::frame_phrase("  Email: hotel_ozbegim@gmail.com                  ", color_cyan);
	Animation::frame_phrase("  Tel: +998 71 246 33 77                          ", color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::frame_phrase("  0. Back                                         ", color_cyan);
	Animation::frame_phrase("                                                  ", color_cyan);
	Animation::draw_border(54, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '0':
				system("cls");
				main_menu();
				break;
			}
		}
	}
}