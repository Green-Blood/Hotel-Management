#include "Animation.h"
#include <iostream>
#include <Windows.h>
#include "Customer.h"
#include <string>
using namespace std;

//"Welcome" animation
void Animation::main_animation()
{
	int color_cyan = 11;
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WEL               ", color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCO             ", color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME           ", color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HO                   ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HOTEL                ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HOTEL UZ             ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HOTEL UZBEK          ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HOTEL UZBEKIS        ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("        WELCOME TO        ", color_cyan);
	frame_phrase("     HOTEL UZBEKISTAN!    ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(200);
	system("cls");
}

//"Good-bye" animation
void Animation::bye()
{
	cout << endl << endl;
	Sleep(100);
	cout << "\r\tTh";
	Sleep(100);
	cout << "\r\tThan";
	Sleep(100);
	cout << "\r\tThanks f";
	Sleep(100);
	cout << "\r\tThanks for";
	Sleep(100);
	cout << "\r\tThanks for com";
	Sleep(100);
	cout << "\r\tThanks for coming!";
	Sleep(100);
	cout << "\r\tThanks for coming! Ho";
	Sleep(100);
	cout << "\r\tThanks for coming! Hope";
	Sleep(200);
	cout << "\r\tThanks for coming! Hope to ";
	Sleep(200);
	cout << "\r\tThanks for coming! Hope to see ";
	Sleep(200);
	cout << "\r\tThanks for coming! Hope to see you ";
	Sleep(200);
	cout << "\r\tThanks for coming! Hope to see you again" << endl;

	cout << endl << endl << endl;
	cout << "\t********" << "\t" << "*        *" << "\t" << "***********" << "    *" << endl;
	cout << "\t*       *" << "\t" << " *      *" << "\t" << "*" << "              *" << endl;
	cout << "\t*        *" << "\t" << "  *    *" << "\t" << "*" << "              *" << endl;
	cout << "\t*       *" << "\t" << "   *  *" << "\t\t" << "*" << "              *" << endl;
	cout << "\t********" << "\t" << "    *" << "\t\t" << "***********" << "    *" << endl;
	cout << "\t*       *" << "\t" << "    *" << "\t\t" << "*" << "              *" << endl;
	cout << "\t*        *" << "\t" << "    *" << "\t\t" << "*" << "              *" << endl;
	cout << "\t*       *" << "\t" << "    *" << "\t\t" << "*" << endl;
	cout << "\t********" << "\t" << "    *" << "\t\t" << "***********" << "    *" << endl;
}

//Initializing animation
void Animation::initializing()
{
	int color_cyan = 11;
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("   VERIFICATION PASSED!   ", color_cyan);
	frame_phrase("      INITIALIZING.       ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(500);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("   VERIFICATION PASSED!   ", color_cyan);
	frame_phrase("      INITIALIZING..      ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(500);
	system("cls");
	cout << endl;
	draw_border(30, color_cyan);
	frame_phrase("                          ", color_cyan);
	frame_phrase("   VERIFICATION PASSED!   ", color_cyan);
	frame_phrase("      INITIALIZING...     ", color_cyan);
	frame_phrase("                          ", color_cyan);
	draw_border(30, color_cyan);
	Sleep(500);
	system("cls");
}

//Draw phrase in borders
void Animation::frame_phrase(string phrase, int color, int count)
{
	string g;
	g = char(176);
	for (int i = 0; i < count; i++)
	{
		cout << "\t";
	}
	colorize_text(g, color);
	colorize_text(g, color);
	cout << phrase;
	colorize_text(g, color);
	colorize_text(g, color);
	cout << endl;
}

//Draw borders
void Animation::draw_border(int amount, int color, int count)
{
	string g;
	g = char(176);

	for (int i = 0; i < count; i++)
	{
		cout << "\t";
	}
	for (int i = 0; i < amount; i++)
	{
		colorize_text(g, color);
	}
	cout << endl;
}

//Colorize text
void Animation::colorize_text(string text, int color)
{
	int color_white = 15;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	SetConsoleTextAttribute(hConsole, color_white);
}


