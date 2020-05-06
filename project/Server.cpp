#include "Controller.h"
#include "Server.h"
#include "Customer.h"
#include "Animation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

//Verification menu
void Server::verification_admin()
{
	char c;
	string psw;
	string lgn;
	int color_cyan = 11;

	cout << endl;
	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("   Verification, Manager:   ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::draw_border(32, color_cyan);
	cout << endl;

	Animation::colorize_text("\t\t    Login: ", 14);
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			log_in();
		}
		if (c == 8)
		{
			if (lgn.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			lgn = lgn.substr(0, lgn.length() - 1);
			continue;
		}
		if (c >= 47 && c <= 58 || c >= 65 && c <= 92 || c >= 97 && c <= 122)
		{
			lgn += c;
			cout << c << '\b' << c;
		}
	}
	cout << endl;

	//Hiding the password with '*'
	Animation::colorize_text("\r\t\t    Password: ", 14);
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			log_in();
		}
		if (c == 8)
		{
			if (psw.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			psw = psw.substr(0, psw.length() - 1);
			continue;
		}
		if (c >= 47 && c <= 58 || c >= 65 && c <= 92 || c >= 97 && c <= 122)
		{
			psw += c;
			cout << "*" << '\b' << "*";
		}
	}

	//Verifying process...
	while (lgn != admin_login || psw != admin_password)
	{
		system("cls");
		cout << endl;
		Animation::draw_border(32, color_cyan);
		Animation::frame_phrase("                            ", color_cyan);
		Animation::frame_phrase("  Wrong login or password!  ", color_cyan);
		Animation::frame_phrase("                            ", color_cyan);
		Animation::draw_border(32, color_cyan);
		Sleep(2000);
		system("cls");
		verification_admin();
	}


	//Go to next menu
	system("cls");
	Animation::initializing();
	menu();
}


//Main menu
void Server::menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Customer temp;
	string mes;
	string space;
	string conv;
	int color_cyan = 11;
	int color_yellow = 14;
	int color_white = 15;
	string g;
	g = char(176);

	int mes_count = temp.get_news_count();
	if (mes_count == 0)
	{
		mes = " ";
	    space = "         ";
	}
	if (mes_count > 0 && mes_count < 10)
	{
		stringstream ss;
		ss << mes_count;
		conv = ss.str();
		mes = "(" + conv + ")";
		space = "       ";
	}
	if (mes_count >= 10)
	{
		stringstream ss;
		ss << mes_count;
		conv = ss.str();
		mes = "(" + conv + ")";
		space = "      ";
	}
	
	ifstream myfile;
	myfile.open("Customers/data.dbb");

	if (myfile.is_open())
	{
		getline(myfile, n_order);
		num = stoi(n_order);
		myfile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'data.dbb' on program path!" << endl;
		exit(1);
	}
	system("cls");
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	Animation::frame_phrase("                                                        ", color_cyan, 1);
	Animation::frame_phrase("                    MANAGER OPTIOS:                     ", color_cyan, 1);
	Animation::frame_phrase("                                                        ", color_cyan, 1);
	Animation::draw_border(60, color_cyan, 1);
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("     CUSTOMER CONTROL:    ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("          SERVICE:          ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                          ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("   1. Add new customer    ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("      M. Messages ", color_white);
	Animation::colorize_text(mes, color_yellow);
	cout << space;
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("   2. Display customer    ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("   3. Search customer     ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("      O. Orders             ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("   4. Customers details   ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                          ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("   0. Log out             ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	cout << "\t";
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                          ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	Animation::colorize_text("                            ", color_white);
	Animation::colorize_text(g + g, color_cyan);
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				add_customer();
				break;
			case '2':
				display_customer();
				break;
			case '3':
				search_customer();
				break;
			case '4':
				display_all();
				break;
			case 'M':
			case 'm':
				display_comp_com();
				break;
			case 'O':
			case 'o':
				display_orders();
				break;
			case '0':
				log_out_admin();
				break;
			}
		}
	}
}


//Add customer
void Server::add_customer()
{
	Customer customer1;   //Temporary object
	ofstream dbout;    //File stream object to write data into file 
	int color_cyan = 11;

	system("cls");
	
	//Getting input from user ( >> overloding )
	cin >> customer1;
	
	//Menu to choose an action
	cout << endl;
	Animation::draw_border(44, color_cyan);
	Animation::frame_phrase("                                        ", color_cyan);
	Animation::frame_phrase("       1. Save      0. Do not save      ", color_cyan);
	Animation::frame_phrase("                                        ", color_cyan);
	Animation::draw_border(44, color_cyan);
	
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				//Creating data file and writing all taken info from user into this file
				dbout.open("Customers/customer" + n_order + ".info");
				dbout << customer1.customer_name << endl;
				dbout << customer1.customer_surname << endl;
				dbout << customer1.customer_age << endl;
				dbout << customer1.customer_oc << endl;
				dbout << customer1.reg_year << endl;
				dbout << customer1.reg_month << endl;
				dbout << customer1.reg_day << endl;
				dbout << customer1.room_type << endl;
				dbout << customer1.debt << endl;
				dbout << customer1.customer_login << endl;
				dbout << customer1.customer_password << endl;
				dbout.close();

				//Create a file which will contain the current amount of customers
				num++;
				dbout.open("Customers/data.dbb");
				dbout << num << endl;
				dbout.close();

				//Message showing the success of operation
				system("cls");
				cout << endl << endl;
				Animation::draw_border(47, color_cyan);
				Animation::frame_phrase("                                           ", color_cyan);
				Animation::frame_phrase(" New customer has been successfully added! ", color_cyan);
				Animation::frame_phrase("                                           ", color_cyan);
				Animation::draw_border(47, color_cyan);
				cout << endl;
				break;
			case '0':
				//Cancel message
				system("cls");
				cout << endl << endl;
				Animation::draw_border(47, color_cyan);
				Animation::frame_phrase("                                           ", color_cyan);
				Animation::frame_phrase("          Process has been canceled!       ", color_cyan);
				Animation::frame_phrase("                                           ", color_cyan);
				Animation::draw_border(47, color_cyan);
				cout << endl;
				break;
			}
			cout << "\t\t\t  Total count of customers: " << num << endl;
			Sleep(2000);
			//Back to the previous menu
			menu();
		}
	}
}


//Display customer
void Server::display_customer()
{
	Customer customer1;
	ifstream myfile;
	int numb;
	int color_cyan = 11;

	system("cls");
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("     DISPLAY CUSTOMER:    ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	cout << endl;
	cout << "\t\t\tCustomer No.: ";
	cin >> numb;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		display_customer();
	}
	else
	{
		if (numb <= 0)
			display_customer();
	}

	if (numb > num)
	{
		system("cls");
		cout << endl;
		Animation::draw_border(50, color_cyan);
		Animation::frame_phrase("                                              ", color_cyan);
		Animation::frame_phrase(" There is no such customer under this number! ", color_cyan);
		Animation::frame_phrase("                                              ", color_cyan);
		Animation::draw_border(50, color_cyan);
		Sleep(2000);
		system("cls");
		menu();
	}
	else
	{
		stringstream ss;
		ss << (numb - 1);
		string order = ss.str();
		myfile.open("Customers/customer" + order + ".info");

		getline(myfile, customer1.customer_name);
		getline(myfile, customer1.customer_surname);
		getline(myfile, customer1.customer_age);
		getline(myfile, customer1.customer_oc);
		getline(myfile, customer1.reg_year);
		getline(myfile, customer1.reg_month);
		getline(myfile, customer1.reg_day);
		getline(myfile, customer1.room_type);
		getline(myfile, customer1.debt);
		getline(myfile, customer1.customer_login);
		getline(myfile, customer1.customer_password);
		
		myfile.close();
	}

	system("cls");
	cout << endl;
	Animation::draw_border(30, color_cyan);
	cout << "\t\t\tCUSTOMER N#: " << numb << endl;
	Animation::draw_border(30, color_cyan);
	cout << endl;
	cout << customer1;
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("  1. Display other one    ", color_cyan);
	Animation::frame_phrase("  0. Back                 ", color_cyan);
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
				display_customer();
				break;
			case '0':
				system("cls");
				menu();
				break;
			}
		}
	}
}


//Search customer
void Server::search_customer()
{
	char c;
	string srch = "";
	Customer temp1;
	int color_cyan = 11;

	system("cls");
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	Animation::frame_phrase("\tNo. \tRoom:\t\tName-Surname:             ", color_cyan, 1);
	Animation::draw_border(60, color_cyan, 1);
	cout << endl;
	cout << "\t\t\tStart searching!" << endl;
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	cout << endl;
	cout << "\t\t\tSearch: " << srch;
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			menu();
		}
		if (c == 8)
		{
			if (srch.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			srch = srch.substr(0, srch.length() - 1);
			system("cls");
			if (srch != "")
			{
				temp1.search_c(srch);
				cout << "\r\t\t\tSearch: " << srch;
			}
			else
			{
				cout << endl;
				Animation::draw_border(60, color_cyan, 1);
				Animation::frame_phrase("\tNo. \tRoom:\t\tName-Surname:             ", color_cyan, 1);
				Animation::draw_border(60, color_cyan, 1);
				cout << endl;
				cout << "\t\t\tStart searching!" << endl;
				cout << endl;
				Animation::draw_border(60, color_cyan, 1);
				cout << endl;
				cout << "\t\t\tSearch: " << srch;
			}
			continue;
		}
		if (c <= 122)
		{
			system("cls");
			srch += c;
			temp1.search_c(srch);
			cout << "\r\t\t\tSearch: " << srch << '\b' << c;
		}
	}

}


//Room details
void Server::room_details()
{

}


//Show all customers
void Server::display_all()
{
	Customer cust1;
	cust1.display_customers();
}


//Orders
void Server::display_orders()
{

}


//Messages
void Server::display_comp_com()
{
	system("cls");
	int color_cyan = 11;
	Customer cust1;
	string choice;
	char c;
	int j = 0;
	cust1.get_all_messages();

	cout << endl << endl;
	Animation::draw_border(86, color_cyan, 0);
	cout << endl;
	cout << "\t\tEnter the N#  (ESC - Back to menu, 0 - Delete all messages): ";
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			menu();
		}
		if (c == 8)
		{
			if (choice.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			choice = choice.substr(0, choice.length() - 1);
			continue;
		}
		if (c >= 47 && c <= 58 || c >= 65 && c <= 92 || c >= 97 && c <= 122)
		{
			choice += c;
			cout << c << '\b' << c;
		}
	}
	if (choice == "0")
	{
		cust1.delete_all_messages();
	}
	else if (choice != "" || choice != "\n")
	{
		cust1.read_message(choice);
	}
	else
		display_comp_com();
}


//Log out manager
void Server::log_out_admin()
{
	//Asks user the permission to exit from account
	system("cls");
	int color_cyan = 11;

	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("       Are you sure?      ", color_cyan);
	Animation::frame_phrase("     Y - Yes   N - No     ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case 'Y':
			case 'y':
				system("cls");
				log_in();
				break;
			case 'N':
			case 'n':
				system("cls");
				menu();
				break;
			}
		}
	}
}




