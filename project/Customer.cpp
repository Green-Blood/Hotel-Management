#include "Customer.h"
#include "Animation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <string>
#include <Windows.h>
using namespace std;

Customer cust[250];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int color_cyan = 11;

//Verification menu

void Customer::verification_customer()
{
	char c;
	string lgn;
	string psw;
	ifstream myfile;

	myfile.open("Customers/data.dbb", ios::_Nocreate);

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
	read_info();

	cout << endl;
	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("   Verification, Customer:  ", color_cyan);
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

	//Checking login from database
	for (int k = 0; k < num; k++)
	{
		if (lgn == cust[k].customer_login && psw == cust[k].customer_password)
		{
			id = k;
			cust[k].idt = k;
			user_exist = true;
			break;
		}
	}
	//Verifying process...
	while (user_exist == false)
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
		verification_customer();
	}


	//Go to next menu
	system("cls");
	Animation::initializing();
	menu();
}

//Main menu

void Customer::menu()
{
	system("cls");
	read_info();
	stringstream ss;
	ss << calculate_total(id);
	string total_debt = ss.str();

	cout << endl;
	Animation::draw_border(32, color_cyan);
	cout << endl;
	cout << "\t\t     Person: ";
	Animation::colorize_text(cust[id].customer_name + " " + cust[id].customer_surname, 14);
	cout << endl;
	cout << "\t\t     Room type: ";
	Animation::colorize_text(cust[id].room_type, 11);
	cout << endl;
	cout << "\t\t     Current debt: ";
	Animation::colorize_text(total_debt + " $", 10);
	cout << endl << endl;
	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     1. Make an order       ", color_cyan);
	Animation::frame_phrase("     2. Write a letter      ", color_cyan);
	Animation::frame_phrase("     3. Mail-box            ", color_cyan);
	Animation::frame_phrase("     4. Room info           ", color_cyan);
	Animation::frame_phrase("     5. Change password     ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     0. Log out             ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::draw_border(32, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				make_order();
				break;
			case '2':
				system("cls");
				menu_comp_com();
				break;
			case '3':
				system("cls");
				mailbox_check(cust[id].idt);
				break;
			case '4':
				system("cls");
				get_bill(id);
				break;
			case '0':
				system("cls");
				log_out_customer();
				break;
			}
		}
	}
}


//Make complaint/compliment

void Customer::menu_comp_com()
{
	read_info();
	stringstream ss;
	ss << calculate_total(id);
	string total_debt = ss.str();

	cout << endl;
	Animation::draw_border(32, color_cyan);
	cout << endl;
	cout << "\t\t     Person: ";
	Animation::colorize_text(cust[id].customer_name + " " + cust[id].customer_surname, 14);
	cout << endl;
	cout << "\t\t     Room type: ";
	Animation::colorize_text(cust[id].room_type, 11);
	cout << endl;
	cout << "\t\t     Current debt: ";
	Animation::colorize_text(total_debt + " $", 10);
	cout << endl << endl;

	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     1. Complaint           ", color_cyan);
	Animation::frame_phrase("     2. Compliment          ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     0. Back                ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::draw_border(32, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				make_complaint();
				break;
			case '2':
				system("cls");
				make_compliment();
				break;
			case '0':
				system("cls");
				menu();
				break;
			}
		}
	}
}

void Customer::make_complaint()
{
	int i = 0;
	bool choosing = true;
	int count_m;
	ofstream dbout;
	stringstream tostring;
	stringstream ss;
	string order;
	ifstream myfile;

	myfile.open("Messages/count1.dbb");
	if (myfile.is_open())
	{
		getline(myfile, order);
		count_m = stoi(order);
		myfile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'Messages/count1.dbb' on program path!" << endl;
		exit(1);
	}

	cout << "\t\tWrite your complaint next: (Press: '+' - to confirm, '-' - to cancel)" << endl << endl;
	cout << "\t\t";
	getline(cin, cust[id].complaint[i]);
	i++;
	cout << "\t\tContinue typing? (Y - yes, N - no)";

	while (choosing)
	{
		if (_kbhit())
		{
			char ch;
			ch = _getch();
			switch (ch)
			{
			case 'y':
				system("cls");
				cout << "\t\tWrite your complaint next: (Press: '+' - to confirm, '-' - to cancel)" << endl << endl;
				for (int k = 0; k < i; k++)
				{
					cout << "\t\t" << cust[id].complaint[k] << endl;
				}
				cout << "\t\t";
				getline(cin, cust[id].complaint[i]);
				i++;
				cout << "\t\tContinue typing? (Y - yes, N - no)";
				break;
			case 'n':
				choosing = false;
				cout << " no" << endl << endl;
				cout << "\t\tPlease press '+' or '-' to finish" << endl;
				while (true)
				{
					if (_kbhit())
					{
						char ch;
						ch = _getch();
						switch (ch)
						{
						case '+':
							tostring << count_m;
							order = tostring.str();
							dbout.open("Messages/complaint" + order + ".info");
							dbout << "complaint" << endl;
							dbout << cust[id].customer_name << endl;
							dbout << cust[id].customer_surname << endl;
							dbout << "new" << endl;
							dbout << cust[id].get_current_time() << endl;
							ss << i;
							cust[id].message_line_count_1 = ss.str();
							dbout << cust[id].message_line_count_1 << endl;
							for (int j = 0; j < i + 1; j++)
							{
								dbout << cust[id].complaint[j] << endl;
							}
							dbout.close();
							count_m++;
							dbout.open("Messages/count1.dbb");
							dbout << count_m << endl;
							dbout.close();
							system("cls");
							menu();
							break;
						case '-':
							system("cls");
							menu();
							break;
						}
					}
				}
				break;
			}
		}
	}
}

void Customer::make_compliment()
{
	int i = 0;
	bool choosing = true;
	int count_m;
	ofstream dbout;
	stringstream tostring;
	stringstream ss;
	string order;
	ifstream myfile;

	myfile.open("Messages/count2.dbb");
	if (myfile.is_open())
	{
		getline(myfile, order);
		count_m = stoi(order);
		myfile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'Messages/count2.dbb' on program path!" << endl;
		exit(1);
	}

	cout << "\t\tWrite your compliment next: (Press: '+' - to confirm, '-' - to cancel)" << endl << endl;
	cout << "\t\t";
	getline(cin, cust[id].compliment[i]);
	i++;
	cout << "\t\tContinue typing? (Y - yes, N - no)";

	while (choosing)
	{
		if (_kbhit())
		{
			char ch;
			ch = _getch();
			switch (ch)
			{
			case 'y':
				system("cls");
				cout << "\t\tWrite your compliment next: (Press: '+' - to confirm, '-' - to cancel)" << endl << endl;
				for (int k = 0; k < i; k++)
				{
					cout << "\t\t" << cust[id].compliment[k] << endl;
				}
				cout << "\t\t";
				getline(cin, cust[id].compliment[i]);
				i++;
				cout << "\t\tContinue typing? (Y - yes, N - no)";
				break;
			case 'n':
				choosing = false;
				cout << " no" << endl << endl;
				cout << "\t\tPlease press '+' or '-' to finish" << endl;
				while (true)
				{
					if (_kbhit())
					{
						char ch;
						ch = _getch();
						switch (ch)
						{
						case '+':
							tostring << count_m;
							order = tostring.str();
							dbout.open("Messages/compliment" + order + ".info");
							dbout << "compliment" << endl;
							dbout << cust[id].customer_name << endl;
							dbout << cust[id].customer_surname << endl;
							dbout << "new" << endl;
							dbout << cust[id].get_current_time() << endl;
							ss << i;
							cust[id].message_line_count_2 = ss.str();
							dbout << cust[id].message_line_count_2 << endl;
							for (int j = 0; j < i + 1; j++)
							{
								dbout << cust[id].compliment[j] << endl;
							}
							dbout.close();
							count_m++;
							dbout.open("Messages/count2.dbb");
							dbout << count_m << endl;
							dbout.close();
							system("cls");
							menu();
							break;
						case '-':
							system("cls");
							menu();
							break;
						}
					}
				}
				break;
			}
		}
	}
}

void Customer::get_all_messages()
{
	read_messages();
	int counter = 0;
	Animation::draw_border(86, color_cyan, 0);
	Animation::frame_phrase("                       CUSTOMER'S COMPLAINTS AND COMPLIMENTS:                     ", color_cyan, 0);
	Animation::draw_border(86, color_cyan, 0);
	cout << endl;
	cout << "\tType:" << "\t\tStatus:" << "\t\tTime\t Date:" << "\t\tFrom:" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (cust[i].sender_name_1 != "")
		{
			if (cust[i].message_type_1 == "complaint")
			{
				if (cust[i].message_status_1 == "new")
				{
					SetConsoleTextAttribute(hConsole, 14);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_1 << "\t" << cust[i].message_status_1 << "\t\t" << cust[i].message_time_1;
					cout << "\t" << cust[i].sender_name_1 << " " << cust[i].sender_surname_1 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (cust[i].message_status_1 == "done")
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_1 << "\t" << cust[i].message_status_1 << "\t\t" << cust[i].message_time_1;
					cout << "\t" << cust[i].sender_name_1 << " " << cust[i].sender_surname_1 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 15);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_1 << "\t" << cust[i].message_status_1 << "\t\t" << cust[i].message_time_1;
					cout << "\t" << cust[i].sender_name_1 << " " << cust[i].sender_surname_1 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
		}
	}
	for (int i = 0; i < 200; i++)
	{
		if (cust[i].sender_name_2 != "")
		{
			if (cust[i].message_type_2 == "compliment")
			{
				if (cust[i].message_status_2 == "new")
				{
					SetConsoleTextAttribute(hConsole, 14);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_2 << "\t" << cust[i].message_status_2 << "\t\t" << cust[i].message_time_2;
					cout << "\t" << cust[i].sender_name_2 << " " << cust[i].sender_surname_2 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (cust[i].message_status_2 == "done")
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_2 << "\t" << cust[i].message_status_2 << "\t\t" << cust[i].message_time_2;
					cout << "\t" << cust[i].sender_name_2 << " " << cust[i].sender_surname_2 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 15);
					cout << "  " << counter + 1 << ".\t" << cust[i].message_type_2 << "\t" << cust[i].message_status_2 << "\t\t" << cust[i].message_time_2;
					cout << "\t" << cust[i].sender_name_2 << " " << cust[i].sender_surname_2 << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
		}
	}
}

void Customer::delete_all_messages()
{
	system("cls");
	ofstream ofile;
	string filename1;
	string filename2;
	string order;
	int key;

	ofile.open("Messages/count1.dbb");
	ofile << "0" << endl;
	ofile.close();
	ofile.open("Messages/count2.dbb");
	ofile << "0" << endl;
	ofile.close();
	read_info();
	read_messages();
	for (int i = 0; i < 250; i++)
	{
		stringstream ss;
		ss << i;
		order = ss.str();
		filename1 = "Messages/complaint" + order + ".info";
		remove(filename1.c_str());
		filename2 = "Messages/compliment" + order + ".info";
		remove(filename2.c_str());
		if (cust[i].message_status_1 == "checked" || cust[i].message_status_1 == "new" || cust[i].message_status_2 == "checked" || cust[i].message_status_2 == "new")
		{
			for (int k = 0; k < 200; k++)
			{
				if ((cust[i].sender_name_1 == cust[k].customer_name && cust[i].sender_surname_1 == cust[k].customer_surname && cust[i].sender_name_1 != "") || (cust[i].sender_name_2 == cust[k].customer_name && cust[i].sender_surname_2 == cust[k].customer_surname && cust[i].sender_name_2 != ""))
				{
					key = k;
					write_message(key, 0);
				}
			}
		}
		cust[i].message_status_1 = "";
		cust[i].message_type_1 = "";
		cust[i].sender_name_1 = "";
		cust[i].sender_surname_1 = "";
		cust[i].message_status_1 = "";
		cust[i].message_time_1 = "";
		cust[i].message_line_count_1 = "";
		for (int j = 0; j < 20; j++)
		{
			cust[i].complaint[j] = "";
		}
		cust[i].message_status_2 = "";
		cust[i].message_type_2 = "";
		cust[i].sender_name_2 = "";
		cust[i].sender_surname_2 = "";
		cust[i].message_status_2 = "";
		cust[i].message_time_2 = "";
		cust[i].message_line_count_2 = "";
		for (int j = 0; j < 20; j++)
		{
			cust[i].compliment[j] = "";
		}
	}

	cout << endl;
	Animation::draw_border(41, color_cyan);
	Animation::frame_phrase("                                     ", color_cyan);
	Animation::frame_phrase("    All messages has been deleted!   ", color_cyan);
	Animation::frame_phrase("                                     ", color_cyan);
	Animation::draw_border(41, color_cyan);
	Sleep(2000);
	Server::menu();
}


//Make an order

void Customer::make_order()
{
	cout << endl;
	Animation::draw_border(32, color_cyan);
	cout << endl;
	cout << "\t\t     Person: ";
	Animation::colorize_text(cust[id].customer_name + " " + cust[id].customer_surname, 14);
	cout << endl;
	cout << "\t\t     Room type: ";
	Animation::colorize_text(cust[id].room_type, 11);
	cout << endl;
	cout << "\t\t     Orders debt: ";
	Animation::colorize_text(cust[id].debt + " $", 10);
	cout << endl << endl;
	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     1. Food                ", color_cyan);
	Animation::frame_phrase("     2. Service             ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("     0. Back                ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::draw_border(32, color_cyan);
	
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				order_food();
				break;
			case '2':
				system("cls");
				break;
			case '0':
				system("cls");
				menu();
				break;
			}
		}
	}
}

void Customer::order_food()
{
	int n = 0; 
	bool is_choosing = true;
	bool is_choosen = false;
	for (int i = 0; i < 9; i++)
	{
		arrow[i] = "     ";
		amount[i] = 0;
	}
	arrow[n] = " --> ";
	display_food();

	while (true)
	{
		while (is_choosing)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case 'D':
				case 'd':
					calculate_debt(total_price());
					write_info(id);
					system("cls");
					cout << endl;
					cout << "\t\t:::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
					cout << "\t\t::                                             ::" << endl;
					cout << "\t\t::  Your order has been sent to hotel manager! ::" << endl;
					cout << "\t\t::         Please wait for confirmation        ::" << endl;
					cout << "\t\t::                                             ::" << endl;
					cout << "\t\t:::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
					Sleep(2000);
					system("cls");
					menu();
					break;
				case 'C':
				case 'c':
					system("cls");
					cout << endl;
					cout << "\t\t:::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
					cout << "\t\t::                                             ::" << endl;
					cout << "\t\t::        Your order has been canceled!        ::" << endl;
					cout << "\t\t::                                             ::" << endl;
					cout << "\t\t:::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
					Sleep(2000);
					system("cls");
				    menu();
					break;
				case 'S':
				case 's':
					for (int i = 0; i < 9; i++)
					{
						arrow[i] = "     ";
					}
					if (n < 8)
					{
						n++;
					}
					else
						n = 0;
					arrow[n] = " --> ";
					system("cls");
					display_food();
					break;
				case 'W':
				case 'w':
					for (int i = 0; i < 9; i++)
					{
						arrow[i] = "     ";
					}
					if (n > 0 && n < 9)
					{
						n--;
					}
					else
						n = 8;
					arrow[n] = " --> ";

					system("cls");
					display_food();
					break;
				case '\r':
					for (int i = 0; i < 9; i++)
					{
						message[i] = "     ";
					}
					message[n] = "Set quantity with +/-";
					system("cls");
					display_food();
					is_choosing = false;
					is_choosen = true;
					break;
				}
			}
		}

		while (is_choosen)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case '+':
					if (amount[n] >= 0)
						amount[n] += 1;
					system("cls");
					display_food();
					break;
				case '-':
					if (amount[n] > 0)
						amount[n] -= 1;
					system("cls");
					display_food();
					break;
				case '\r':
					for (int i = 0; i < 9; i++)
					{
						message[i] = "     ";
					}
					system("cls");
					display_food();
					is_choosen = false;
					is_choosing = true;
					break;
				}
			}
		}
	}
}

float Customer::food_price(float p, int a)
{
	return p*a;
}

float Customer::total_price()
{
	float t_p = 0;
	for (int i = 0; i < 9; i++)
	{
		t_p += food_price(price[i], amount[i]);
	}
	return t_p;
}

void Customer::display_food()
{
	food[0] = "Cofe";
	food[1] = "Broad";
	food[2] = "Kebab";
	food[3] = "Coca-cola";
	food[4] = "Ice-cream";
	food[5] = "Cake";
	food[6] = "Breakfast";
	food[7] = "Dinner";
	food[8] = "Soup";
	price[0] = 1.5;
	price[1] = 1.0;
	price[2] = 20;
	price[3] = 4;
	price[4] = 3.2;
	price[5] = 5.2;
	price[6] = 12;
	price[7] = 25;
	price[8] = 8;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	cout << "::                                                                                                              ::" << endl;
	cout << "::      Choose options of food and set their quantity: (W - up arrow, S - down arrow, Enter - select)           ::" << endl;
	cout << "::                   (When you done press 'D' to confirm order or 'C' to cancel all)                            ::" << endl;
	cout << "::                                                                                                              ::" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl << endl;
	cout << "\t\t\t" << "Name:" << "\t\t" << "Price:" << "      " << "Quantity:" << "\t\t" << "Sum:" << endl;
	cout << "\t\t" << arrow[0] << "1) " << food[0] << "\t\t" << price[0] << "$:" << "\t\tx" << amount[0] << "\t\t" << food_price(price[0], amount[0]) << "$" << "\t" << message[0] << endl;
	cout << "\t\t" << arrow[1] << "2) " << food[1] << "\t\t" << price[1] << "$:" << "\t\tx" << amount[1] << "\t\t" << food_price(price[1], amount[1]) << "$" << "\t" << message[1] << endl;
	cout << "\t\t" << arrow[2] << "3) " << food[2] << "\t\t" << price[2] << "$:" << "\t\tx" << amount[2] << "\t\t" << food_price(price[2], amount[2]) << "$" << "\t" << message[2] << endl;
	cout << "\t\t" << arrow[3] << "4) " << food[3] << "\t" << price[3] << "$:" << "\t\tx" << amount[3] << "\t\t" << food_price(price[3], amount[3]) << "$" << "\t" << message[3] << endl;
	cout << "\t\t" << arrow[4] << "5) " << food[4] << "\t" << price[4] << "$:" << "\t\tx" << amount[4] << "\t\t" << food_price(price[4], amount[4]) << "$" << "\t" << message[4] << endl;
	cout << "\t\t" << arrow[5] << "6) " << food[5] << "\t\t" << price[5] << "$:" << "\t\tx" << amount[5] << "\t\t" << food_price(price[5], amount[5]) << "$" << "\t" << message[5] << endl;
	cout << "\t\t" << arrow[6] << "7) " << food[6] << "\t" << price[6] << "$:" << "\t\tx" << amount[6] << "\t\t" << food_price(price[6], amount[6]) << "$" << "\t" << message[6] << endl;
	cout << "\t\t" << arrow[7] << "8) " << food[7] << "\t\t" << price[7] << "$:" << "\t\tx" << amount[7] << "\t\t" << food_price(price[7], amount[7]) << "$" << "\t" << message[7] << endl;
	cout << "\t\t" << arrow[8] << "9) " << food[8] << "\t\t" << price[8] << "$:" << "\t\tx" << amount[8] << "\t\t" << food_price(price[8], amount[8]) << "$" << "\t" << message[8] << endl;
	cout << "\t\t" << endl;
	cout << "\t\t" << "\t" << "Total price: " << total_price() << "$" << endl << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

void Customer::calculate_debt(float s)
{
	double temp = ::atof(cust[id].debt.c_str());
	cust[id].total_p = temp;
	cust[id].total_p += s;
}

void Customer::search_customer(string n, string sn)
{
	bool search_found = false;
	int ident;
	read_info();
	for (int i = 0; i < 250; i++)
	{
		if (n == cust[i].customer_name && sn == cust[i].customer_surname)
		{
			search_found = true;
			ident = i;
			break;
		}
	}
	if (search_found == true)
	{
		system("cls");
		cout << "\t\t::::::::::::::::::::::::::::::" << endl;
		cout << "\t\t\tCUSTOMER N#: " << ident + 1 << endl;
		cout << "\t\t::::::::::::::::::::::::::::::" << endl << endl;
		cout << cust[ident];
		cout << endl << endl;
		cout << "\t\t::::::::::::::::::::::::::::::" << endl;
		cout << "\t\t::                          ::" << endl;
		cout << "\t\t::  1. Display other one    ::" << endl;
		cout << "\t\t::  0. Back                 ::" << endl;
		cout << "\t\t::                          ::" << endl;
		cout << "\t\t::::::::::::::::::::::::::::::" << endl;

		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case '1':
					system("cls");
					Server::search_customer();
					break;
				case '0':
					system("cls");
					Server::menu();
					break;
				}
			}
		}
	}
	else if (search_found == false)
	{
		system("cls");
		cout << endl;
		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
		cout << "\t\t::                                              ::" << endl;
		cout << "\t\t::     There is no such customer in database!   ::" << endl;
		cout << "\t\t::                                              ::" << endl;
		cout << "\t\t::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
		Sleep(2000);
		system("cls");
		Server::menu();
	}
	
}

void Customer::search_c(string sr)
{
	ifstream myfile;
	bool found = false;
	string complex;

	myfile.open("Customers/data.dbb", ios::_Nocreate);

	if (myfile.is_open())
	{
		getline(myfile, n_order);
		num = stoi(n_order);
		myfile.close();
	}
	for (int i = 0; i <= num; i++)
	{
		stringstream ss;
		ss << i;
		string order = ss.str();
		myfile.open("Customers/customer" + order + ".info");
		getline(myfile, cust[i].customer_name);
		getline(myfile, cust[i].customer_surname);
		getline(myfile, cust[i].customer_age);
		getline(myfile, cust[i].customer_oc);
		getline(myfile, cust[i].reg_year);
		getline(myfile, cust[i].reg_month);
		getline(myfile, cust[i].reg_day);
		getline(myfile, cust[i].room_type);
		getline(myfile, cust[i].debt);
		getline(myfile, cust[i].customer_login);
		getline(myfile, cust[i].customer_password);
		myfile.close();
	}

	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	Animation::frame_phrase("\tNo. \tRoom:\t\tName-Surname:             ", color_cyan, 1);
	Animation::draw_border(60, color_cyan, 1);
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		stringstream ss;
		ss << i + 1;
		string ord = ss.str();
		complex = cust[i].customer_name + " " + cust[i].customer_surname;
		if (sr == cust[i].customer_name.substr(0, sr.length()))
		{
			found = true;
			cout << "\t\t" << i + 1 << "." << "\t" << cust[i].room_type << "\t\t";
			Animation::colorize_text(cust[i].customer_name.substr(0, sr.length()), 14);
			cout << cust[i].customer_name.substr(sr.length()) << " " << cust[i].customer_surname  << endl;
		}
		else if (sr == cust[i].customer_surname.substr(0, sr.length()))
		{
			found = true;
			cout << "\t\t" << i + 1 << "." << "\t" << cust[i].room_type << "\t\t" << cust[i].customer_name << " ";
			Animation::colorize_text(cust[i].customer_surname.substr(0, sr.length()), 14);
			cout << cust[i].customer_surname.substr(sr.length()) << endl;
		}
		else if (sr == complex.substr(0, sr.length()))
		{
			found = true;
			cout << "\t\t" << i + 1 << "." << "\t" << cust[i].room_type << "\t\t";
			Animation::colorize_text(complex.substr(0, sr.length()), 14);
			cout << cust[i].customer_surname.substr(sr.length() - cust[i].customer_name.length() - 1) << endl;
		}
		else if (sr == cust[i].room_type.substr(0, sr.length()))
		{
			found = true;
			cout << "\t\t" << i + 1 << "." << "\t";
			Animation::colorize_text(cust[i].room_type.substr(0, sr.length()), 14);
			cout << cust[i].room_type.substr(sr.length()) << "\t\t" << cust[i].customer_name << " " << cust[i].customer_surname << endl;
		}
		else if (sr == ord)
		{
			found = true;
			cout << "\t\t";
			Animation::colorize_text(ord.substr(0, sr.length()), 14);
			cout << ord.substr(sr.length()) << ".\t" << cust[i].room_type << "\t\t" << cust[i].customer_name << " " << cust[i].customer_surname << endl;
		}
	}
	if (!found)
	{
		cout << "\t\t\tNo user found!" << endl;
	}
	cout << endl;
	Animation::draw_border(60, color_cyan, 1);
	cout << endl;
}

//I/O info

void Customer::display_customers()
{
	system("cls");
	ifstream myfile;
	for (int i = 0; i < 250; i++)
	{
		stringstream ss;
		ss << i;
		string order = ss.str();
		myfile.open("Customers/customer" + order + ".info", ios::_Nocreate);
		getline(myfile, cust[i].customer_name);
		getline(myfile, cust[i].customer_surname);
		getline(myfile, cust[i].customer_age);
		getline(myfile, cust[i].customer_oc);
		getline(myfile, cust[i].reg_year);
		getline(myfile, cust[i].reg_month);
		getline(myfile, cust[i].reg_day);
		getline(myfile, cust[i].room_type);
		getline(myfile, cust[i].debt);
		getline(myfile, cust[i].customer_login);
		getline(myfile, cust[i].customer_password);
		myfile.close();
	}
	Animation::draw_border(91, color_cyan, 0);
	Animation::frame_phrase("                             ALL CUSTOMERS BRIEF INFO:                                 ", color_cyan, 0);
	Animation::draw_border(91, color_cyan, 0);
	cout << endl;
	cout << "\tNo.\tReg. day:" << "\tDebt:" << "\t\tRoom type:" << "\tName/Surname:" << endl << endl;
	for (int i = 0; i < 250; i++)
	{
		if (cust[i].customer_name != "")
		{
			cout << "\t" << i + 1 << ".\t" << cust[i].reg_day << "." << cust[i].reg_month << "." << cust[i].reg_year << "\t" << cust[i].debt << " $\t\t" << cust[i].room_type;
			cout << "\t\t" << cust[i].customer_name << " " << cust[i].customer_surname << endl;
		}
	}
	cout << endl;
	Animation::draw_border(91, color_cyan, 0);
	Animation::frame_phrase("               1. Delete all customers                        0. Back                  ", color_cyan, 0);
	Animation::draw_border(91, color_cyan, 0);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '0':
				Server::menu();
				break;
			case '1':
				delete_all_customers();
				break;
			}
		}
	}
}

void Customer::write_info(int c)
{
	ofstream dbout;
	stringstream ss;
	ss << c;
	string order = ss.str();
	dbout.open("Customers/customer" + order + ".info");
	dbout << cust[c].customer_name << endl;
	dbout << cust[c].customer_surname << endl;
	dbout << cust[c].customer_age << endl;
	dbout << cust[c].customer_oc << endl;
	dbout << cust[c].reg_year << endl;
	dbout << cust[c].reg_month << endl;
	dbout << cust[c].reg_day << endl;
	dbout << cust[c].room_type << endl;
	dbout << cust[c].total_p << endl;
	dbout << cust[c].customer_login << endl;
	dbout << cust[c].customer_password << endl;
	dbout.close();
}

void Customer::read_info()
{
	for (int i = 0; i <= num; i++)
	{
		ifstream myfile;
		stringstream ss;
		ss << i;
		string order = ss.str();
		myfile.open("Customers/customer" + order + ".info");
		getline(myfile, cust[i].customer_name);
		getline(myfile, cust[i].customer_surname);
		getline(myfile, cust[i].customer_age);
		getline(myfile, cust[i].customer_oc);
		getline(myfile, cust[i].reg_year);
		getline(myfile, cust[i].reg_month);
		getline(myfile, cust[i].reg_day);
		getline(myfile, cust[i].room_type);
		getline(myfile, cust[i].debt);
		getline(myfile, cust[i].customer_login);
		getline(myfile, cust[i].customer_password);
		myfile.close();
	}
}

void Customer::read_messages()
{
	int m_1;
	int m_2;
	int n_1;
	int n_2;
	ifstream ifile;
	string st_1;
	string st_2;

	ifile.open("Messages/count1.dbb", ios::_Nocreate);
	if (ifile.is_open())
	{
		getline(ifile, st_1);
		m_1 = stoi(st_1);
		ifile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'Messages/count1.dbb' on program path!" << endl;
		exit(1);
	}

	ifile.open("Messages/count2.dbb", ios::_Nocreate);
	if (ifile.is_open())
	{
		getline(ifile, st_2);
		m_2 = stoi(st_2);
		ifile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'Messages/count2.dbb' on program path!" << endl;
		exit(1);
	}

	for (int i = 0; i < m_1; i++)
	{
		stringstream ss;
		ss << i;
		string order = ss.str();
		ifile.open("Messages/complaint" + order + ".info", ios::_Nocreate);
		getline(ifile, cust[i].message_type_1);
		getline(ifile, cust[i].sender_name_1);
		getline(ifile, cust[i].sender_surname_1);
		getline(ifile, cust[i].message_status_1);
		getline(ifile, cust[i].message_time_1);
		getline(ifile, cust[i].message_line_count_1);
		n_1 = stoi(cust[i].message_line_count_1);
		for (int j = 0; j < n_1 + 1; j++)
		{
			getline(ifile, cust[i].complaint[j]);
		}
		ifile.close();
	}

	for (int i = 0; i < m_2; i++)
	{
		stringstream ss;
		ss << i;
		string order = ss.str();
		ifile.open("Messages/compliment" + order + ".info", ios::_Nocreate);
		getline(ifile, cust[i].message_type_2);
		getline(ifile, cust[i].sender_name_2);
		getline(ifile, cust[i].sender_surname_2);
		getline(ifile, cust[i].message_status_2);
		getline(ifile, cust[i].message_time_2);
		getline(ifile, cust[i].message_line_count_2);
		n_2 = stoi(cust[i].message_line_count_2);
		for (int j = 0; j < n_2 + 1; j++)
		{
			getline(ifile, cust[i].compliment[j]);
		}
		ifile.close();
	}
}

int Customer::get_news_count()
{
	int c_m = 0;
	read_messages();
	for (int i = 0; i < 250; i++)
	{
		if (cust[i].message_status_1 == "new")
			c_m++;
		if (cust[i].message_status_2 == "new")
			c_m++;
	}

	return c_m;
}

void operator<<(ostream &out, Customer &s)
{
	int color_yellow = 14;
	Animation::colorize_text("\t\tName/Surname: ", color_yellow);
	out << s.customer_name << " " << s.customer_surname << endl << endl;
	Animation::colorize_text("\t\tAge: ", color_yellow);
	out << s.customer_age << endl;
	Animation::colorize_text("\t\tOccupation: ", color_yellow);
	out << s.customer_oc << endl << endl;
	Animation::colorize_text("\t\tCheck-in date: ", color_yellow);
	out << s.reg_day << "-" << s.reg_month << "-" << s.reg_year << endl;
	Animation::colorize_text("\t\tRoom type: ", color_yellow);
	out << s.room_type << endl << endl;
	Animation::colorize_text("\t\tCurrent debt: ", color_yellow);
	out << s.debt << "$" << endl << endl;
	Animation::colorize_text("\t\tLogin: ", color_yellow);
	out << s.customer_login << endl;
	Animation::colorize_text("\t\tPassword: ", color_yellow);
	out << s.customer_password << endl;
}

void operator>>(istream &in, Customer &s)
{
	ifstream myfile;
	char c;
	int color_yellow = 14;

	myfile.open("Customers/data.dbb");

	if (myfile.is_open())
	{
		getline(myfile, s.n_order);
		s.num = stoi(s.n_order);
		myfile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'data.dbb' on program path!" << endl;
		exit(1);
	}
	cout << endl;
	Animation::draw_border(44, color_cyan);
	cout << endl;
	cout << "\t\t  Enter infromation about customer No. " << s.num + 1 << ": " << endl << endl;
	Animation::draw_border(44, color_cyan);
	cout << endl;
	Animation::colorize_text("\t\t    Name: ", color_yellow);
	if ((c = _getch()) == 27)
	{
		system("cls");
		s.Server::menu();
	}
	in >> s.customer_name;
	Animation::colorize_text("\t\t    Surname: ", color_yellow);
	in >> s.customer_surname;
	Animation::colorize_text("\t\t    Age: ", color_yellow);
	in >> s.customer_age;
	Animation::colorize_text("\t\t    Occupation: ", color_yellow);
	in >> s.customer_oc;
	cout << endl;
	Animation::colorize_text("\t\t    Check-in date: ", color_yellow);
	cout << endl;
	Animation::colorize_text("\t\t    Year: ", color_yellow);
	in >> s.reg_year;
	Animation::colorize_text("\t\t    Month: ", color_yellow);
	in >> s.reg_month;
	Animation::colorize_text("\t\t    Day: ", color_yellow);
	in >> s.reg_day;
	cout << endl;
	Animation::colorize_text("\t\t    Select Room type: ", color_yellow);
	cout << endl;
	Animation::colorize_text("\t\t    1) Deluxe", 15);
	cout << endl;
	Animation::colorize_text("\t\t    2) Luxury", 15);
	cout << endl;
	Animation::colorize_text("\t\t    3) Premium", 15);
	cout << endl;

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				s.room_type = "deluxe";
				break;
			case '2':
				s.room_type = "luxury";
				break;
			case '3':
				s.room_type = "premium";
				break;
			default:
				s.room_type = "deluxe";
			}
			break;
		}
	}

	cout << endl;
	Animation::colorize_text("\t\t    Room type: ", color_yellow);
	cout << s.room_type << endl << endl;
	s.debt = "0";
	Animation::colorize_text("\t\t    Login: ", color_yellow);
	in >> s.customer_login;
	Animation::colorize_text("\t\t    Password: ", color_yellow);
	in >> s.customer_password;
	cout << endl;
}

void Customer::delete_all_customers()
{
	ofstream dbout;
	string filename;
	string psw;
	char c;
	system("cls");
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
				cout << endl;
				Animation::draw_border(58, color_cyan);
				Animation::frame_phrase("         TO CONFIRM AN ACTION ENTER PASSWORD:         ", color_cyan);
				Animation::draw_border(58, color_cyan);
				cout << endl;

				Animation::colorize_text("\t\t    Password: ", 14);
				while ((c = _getch()) != '\r')
				{
					if (c == 27)
					{
						system("cls");
						display_all();
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
				if (psw != admin_password)
				{
					system("cls");
					cout << endl;
					Animation::draw_border(30, color_cyan);
					Animation::frame_phrase("                          ", color_cyan);
					Animation::frame_phrase("      Wrong password!     ", color_cyan);
					Animation::frame_phrase("                          ", color_cyan);
					Animation::draw_border(30, color_cyan);
					Sleep(2000);
					system("cls");
					display_all();
				}
				else if (psw == admin_password)
				{
					system("cls");
					dbout.open("Customers/data.dbb");
					dbout << "0" << endl;
					dbout.close();
					for (int i = 0; i < 250; i++)
					{
						stringstream ss;
						ss << i;
						string order = ss.str();
						filename = "Customers/customer" + order + ".info";
						remove(filename.c_str());
						cust[i].customer_name = "";
						cust[i].customer_surname = "";
						cust[i].customer_age = "";
						cust[i].customer_oc = "";
						cust[i].reg_year = "";
						cust[i].reg_month = "";
						cust[i].reg_day = "";
						cust[i].room_type = "";
						cust[i].debt = "";
						cust[i].customer_login = "";
						cust[i].customer_password = "";
					}
					cout << endl;
					Animation::draw_border(68, color_cyan);
					Animation::frame_phrase("         All customers has been removed from database!          ", color_cyan);
					Animation::draw_border(68, color_cyan);
					Sleep(2000);
					Server::menu();
				}
				break;
			case 'N':
			case 'n':
				system("cls");
				display_all();
				break;
			}
		}
	}
}

void Customer::get_bill(int g)
{
	update_data(g);
	cout << endl;
	Animation::draw_border(36, color_cyan);
	Animation::frame_phrase("                                ", color_cyan);
	Animation::frame_phrase("        ROOM BRIEF INFO:        ", color_cyan);
	Animation::frame_phrase("                                ", color_cyan);
	Animation::draw_border(36, color_cyan);
	cout << endl;
	Animation::colorize_text("\t\t     Person: ", 14);
	cout << cust[g].customer_name << " " << cust[g].customer_surname << endl;
	Animation::colorize_text("\t\t     Check-in date: ", 14);
	cout << cust[g].reg_day << "." << cust[g].reg_month << "." << cust[g].reg_year << endl;
	Animation::colorize_text("\t\t     In the hotel: ", 14);
	cout << cust[g].stay_days << " days" << endl;
	Animation::colorize_text("\t\t     Orders cost: ", 14);
	cout << stoi(cust[g].debt) << " $" << endl;
	Animation::colorize_text("\t\t     Room type: ", 14);
	cout << cust[g].room_type << endl;
	Animation::colorize_text("\t\t     Room cost: ", 14);
	cout << cust[g].daily_cost << " $ per day" << endl << endl;

	Animation::colorize_text("\t\t     Total cost: ", 10);
	cout << calculate_total(g) << " $" << endl;

	cout << endl << endl;
	Animation::draw_border(36, color_cyan);
	Animation::frame_phrase("          0. Back               ", color_cyan);
	Animation::draw_border(36, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '0':
				system("cls");
				menu();
				break;
			}
		}
	}
}

float Customer::calculate_total(int cus_id)
{
	float room_cost;

	update_data(cus_id);

	room_cost = cust[cus_id].daily_cost * cust[cus_id].stay_days + stoi(cust[cus_id].debt);

	return room_cost;
}

void Customer::update_data(int cus_id)
{
	if (cust[cus_id].room_type == "deluxe")
	{
		cust[cus_id].daily_cost = 200;
	}
	if (cust[cus_id].room_type == "luxury")
	{
		cust[cus_id].daily_cost = 400;
	}
	if (cust[cus_id].room_type == "premium")
	{
		cust[cus_id].daily_cost = 800;
	}

	int year, month, day;

	//Using built-in methods from <time.h> library
	struct tm newtime;
	__time32_t int_time;
	errno_t err;

	//Converting date to integer
	_time32(&int_time);
	err = _localtime32_s(&newtime, &int_time);

	//Current date taken from computer
	year = 1900 + newtime.tm_year;
	month = 1 + newtime.tm_mon;
	day = newtime.tm_mday;

	cust[cus_id].stay_days = (year - stoi(cust[cus_id].reg_year)) * 365 + (month - stoi(cust[cus_id].reg_month)) * 30 + (day - stoi(cust[cus_id].reg_day));
}

//Mail box menu

void Customer::mailbox_check(int ide)
{
	system("cls");
	ifstream ifile;
	int counter = 0;
	stringstream ss;
	ss << ide;
	string order = ss.str();
	string order1;
	Animation::draw_border(86, color_cyan, 0);
	Animation::frame_phrase("                             YOUR MESSAGES IN MAILBOX:                            ", color_cyan, 0);
	Animation::draw_border(86, color_cyan, 0);
	cout << endl;
	cout << "\tType:" << "\t\tStatus:" << "\t\tTime\t Date:" << "\t\tFrom:" << endl;
	for (int i = 0; i < 100; i++)
	{
		stringstream ss1;
		ss1 << i;
		order1 = ss1.str();
		ifile.open("Mailbox/" + order + "/mail" + order1 + ".m", ios::_Nocreate);
		if (ifile.is_open())
		{
			getline(ifile, cust[ide].sender_name);
			getline(ifile, cust[ide].message_type);
			getline(ifile, cust[ide].message_status);
			getline(ifile, cust[ide].message_time);
			for (int k = 0; k < 5; k++)
			{
				getline(ifile, cust[id].answer[k]);
			}
			ifile.close();

			if (cust[ide].sender_name != "")
			{
				if (cust[ide].message_status == "done")
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "  " << counter + 1 << ".\t" << cust[ide].message_type << "\t" << cust[ide].message_status << "\t\t" << cust[ide].message_time;
					cout << "\t" << cust[ide].sender_name << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
				else if (cust[id].message_status == "ignored")
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "  " << counter + 1 << ".\t" << cust[ide].message_type << "\t" << cust[ide].message_status << "\t\t" << cust[ide].message_time;
					cout << "\t" << cust[ide].sender_name << endl;
					counter++;
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
		}
		else
			break;
	}
	string choice;
	char c;

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
		delete_all_mails(ide);
	}
	else if (choice != "" || choice != "\n")
	{
		read_mail(choice, ide);
	}
	else
	{
		system("cls");
		mailbox_check(ide);
	}
}

string Customer::get_current_time()
{
	string date_time;
	int year, month, day;
	stringstream ss;
	int hour, min;
	//Using built-in methods from <time.h> library
	struct tm newtime;
	__time32_t int_time;
	errno_t err;

	//Converting date to integer
	_time32(&int_time);
	err = _localtime32_s(&newtime, &int_time);

	//Current date taken from computer
	year = 1900 + newtime.tm_year;
	month = 1 + newtime.tm_mon;
	day = newtime.tm_mday;
	hour = newtime.tm_hour;
	min = newtime.tm_min;
	if (hour < 10)
	{
		ss << "0";
		ss << hour;
	}
	else
		ss << hour;
	if (min < 10)
	{
		ss << ":";
		ss << "0";
		ss << min;
	}
	else
	{
		ss << ":";
		ss << min;
	}
	ss << "    ";
	if (day < 10)
	{
		ss << "0";
		ss << day;
		ss << ".";
	}
	else
	{
		ss << day;
		ss << ".";
	}
	if (month < 10)
	{
		ss << "0";
		ss << month;
		ss << ".";
	}
	else
	{
		ss << month;
		ss << ".";
	}
	ss << year;
	date_time = ss.str();
	return date_time;
}

void Customer::read_message(string ch)
{
	system("cls");
	read_info();
	read_messages();
	ifstream ifile;
	ofstream ofile;
	stringstream ss;
	stringstream ss1;
	stringstream ss2;
	string order;
	string order1;
	string order2;
	int m_1;
	int n, m;
	string st_1;
	string st_2;

	ifile.open("Messages/count1.dbb");
	if (ifile.is_open())
	{
		getline(ifile, st_1);
		m_1 = stoi(st_1);
		ifile.close();
	}
	else
	{
		system("cls");
		cout << "Cannot open file 'Messages/count1.dbb' on program path!" << endl;
		exit(1);
	}

	ss << ch;
	order = ss.str();
	m = stoi(order) - 1;
	if (cust[m].message_type_1 == "complaint")
	{
		n = stoi(cust[m].message_line_count_1);
		cout << endl;
		Animation::draw_border(44, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\tFrom: ", 14);
		cout << cust[m].sender_name_1 << " " << cust[m].sender_surname_1 << endl;
		Animation::colorize_text("\t\tType: ", 14);
		cout << cust[m].message_type_1 << endl;
		Animation::colorize_text("\t\tTime and Date: ", 14);
		cout << cust[m].message_time_1 << endl << endl;
		Animation::draw_border(44, color_cyan);
		cout << endl;
		for (int i = 0; i < n + 1; i++)
		{
			Animation::colorize_text("\t\t" + cust[m].complaint[i], 14);
			cout << endl;
		}
		cout << endl;
		Animation::draw_border(44, color_cyan);
		Animation::frame_phrase("  1. Mark as done        0. Back        ", color_cyan);
		Animation::draw_border(44, color_cyan);
		SetConsoleTextAttribute(hConsole, 15);
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case '1':
					int key;
					system("cls");
					ss1 << m;
					order1 = ss1.str();
					cust[m].message_status_1 = "done";
					ofile.open("Messages/complaint" + order1 + ".info");
					ofile << cust[m].message_type_1 << endl;
					ofile << cust[m].sender_name_1 << endl;
					ofile << cust[m].sender_surname_1 << endl;
					ofile << cust[m].message_status_1 << endl;
					ofile << cust[m].message_time_1 << endl;
					ofile << cust[m].message_line_count_1 << endl;
					for (int j = 0; j < stoi(cust[m].message_line_count_1) + 1; j++)
					{
						ofile << cust[m].complaint[j] << endl;
					}
					ofile.close();
					for (int k = 0; k < 200; k++)
					{
						if (cust[m].sender_name_1 == cust[k].customer_name && cust[m].sender_surname_1 == cust[k].customer_surname && cust[m].sender_name_1 != "")
							key = k;
					}
					write_message(key, 1);
					display_comp_com();
					break;
				case '0':
					system("cls");
					ss1 << m;
					order1 = ss1.str();
					cust[m].message_status_1 = "checked";
					ofile.open("Messages/complaint" + order1 + ".info");
					ofile << cust[m].message_type_1 << endl;
					ofile << cust[m].sender_name_1 << endl;
					ofile << cust[m].sender_surname_1 << endl;
					ofile << cust[m].message_status_1 << endl;
					ofile << cust[m].message_time_1 << endl;
					ofile << cust[m].message_line_count_1 << endl;
					for (int j = 0; j < stoi(cust[m].message_line_count_1) + 1; j++)
					{
						ofile << cust[m].complaint[j] << endl;
					}
					ofile.close();
					display_comp_com();
					break;
				}
			}
		}
	}
	if (cust[m - m_1].message_type_2 == "compliment")
	{
		n = stoi(cust[m - m_1].message_line_count_2);
		cout << endl;
		Animation::draw_border(44, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\tFrom: ", 14);
		cout << cust[m - m_1].sender_name_2 << " " << cust[m - m_1].sender_surname_2 << endl;
		Animation::colorize_text("\t\tType: ", 14);
		cout << cust[m - m_1].message_type_2 << endl;
		Animation::colorize_text("\t\tTime and Date: ", 14);
		cout << cust[m - m_1].message_time_2 << endl;
		Animation::draw_border(44, color_cyan);
		cout << endl;
		for (int i = 0; i < n + 1; i++)
		{
			Animation::colorize_text("\t\t" + cust[m - m_1].compliment[i], 14);
			cout << endl;
		}
		cout << endl;
		Animation::draw_border(44, color_cyan);
		Animation::frame_phrase("  1. Mark as done        0. Back        ", color_cyan);
		Animation::draw_border(44, color_cyan);
		SetConsoleTextAttribute(hConsole, 15);
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case '1':
					int key;
					system("cls");
					ss2 << m - m_1;
					order2 = ss2.str();
					cust[m - m_1].message_status_2 = "done";
					ofile.open("Messages/compliment" + order2 + ".info");
					ofile << cust[m - m_1].message_type_2 << endl;
					ofile << cust[m - m_1].sender_name_2 << endl;
					ofile << cust[m - m_1].sender_surname_2 << endl;
					ofile << cust[m - m_1].message_status_2 << endl;
					ofile << cust[m - m_1].message_time_2 << endl;
					ofile << cust[m - m_1].message_line_count_2 << endl;
					for (int j = 0; j < stoi(cust[m - m_1].message_line_count_2) + 1; j++)
					{
						ofile << cust[m - m_1].compliment[j] << endl;
					}
					ofile.close();
					for (int k = 0; k < 200; k++)
					{
						if (cust[m - m_1].sender_name_2 == cust[k].customer_name && cust[m - m_1].sender_surname_2 == cust[k].customer_surname && cust[m - m_1].sender_name_2 != "")
							key = k;
					}
					write_message(key, 1);
					display_comp_com();
					break;
				case '0':
					system("cls");
					ss2 << m - m_1;
					order2 = ss2.str();
					cust[m - m_1].message_status_2 = "checked";
					ofile.open("Messages/compliment" + order2 + ".info");
					ofile << cust[m - m_1].message_type_2 << endl;
					ofile << cust[m - m_1].sender_name_2 << endl;
					ofile << cust[m - m_1].sender_surname_2 << endl;
					ofile << cust[m - m_1].message_status_2 << endl;
					ofile << cust[m - m_1].message_time_2 << endl;
					ofile << cust[m - m_1].message_line_count_2 << endl;
					for (int j = 0; j < stoi(cust[m - m_1].message_line_count_2) + 1; j++)
					{
						ofile << cust[m - m_1].compliment[j] << endl;
					}
					ofile.close();
					display_comp_com();
					break;
				}
			}
		}
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << endl;
		Animation::draw_border(47, color_cyan);
		Animation::frame_phrase("                                           ", color_cyan);
		Animation::frame_phrase("      This message does not exist yet!     ", color_cyan);
		Animation::frame_phrase("                                           ", color_cyan);
		Animation::draw_border(47, color_cyan);
		Sleep(2000);
		system("cls");
		display_comp_com();
	}
}

void Customer::write_message(int id, int s)
{
	ofstream ofile;
	ifstream ifile;
	stringstream ss;
	string cur;
	int cur_int;
	ss << id;
	string order = ss.str();
	ifile.open("Mailbox/" + order + "/c.dat");
	getline(ifile, cur);
	cur_int = stoi(cur) + 1;
	ifile.close();
	cust[id].sender_name = "Manager";
	cust[id].message_type = "confirmation";
	if (s == 1)
	{
		cust[id].message_status = "done";
		cust[id].message_type = "confirmation";
		cust[id].message_time = cust[id].get_current_time();
		ofile.open("Mailbox/" + order + "/mail" + cur + ".m");
		ofile << cust[id].sender_name << endl;
		ofile << cust[id].message_type << endl;
		ofile << cust[id].message_status << endl;
		ofile << cust[id].message_time << endl;
		ofile << "Your request has been done! If you have any problems you can ask again" << endl;
		ofile.close();

		ofile.open("Mailbox/" + order + "/c.dat");
		ofile << cur_int << endl;
		ofile.close();
	}
	else if (s == 0)
	{
		cust[id].message_status = "ignored";
		cust[id].message_type = "notification";
		cust[id].message_time = cust[id].get_current_time();
		ofile.open("Mailbox/" + order + "/mail" + cur + ".m");
		ofile << cust[id].sender_name << endl;
		ofile << cust[id].message_type << endl;
		ofile << cust[id].message_status << endl;
		ofile << cust[id].message_time << endl;
		ofile << "Your request has been ignored!" << endl;
		ofile.close();

		ofile.open("Mailbox/" + order + "/c.dat");
		ofile << cur_int << endl;
		ofile.close();
	}
}

void Customer::read_mail(string ch, int ide)
{
	system("cls");
	SetConsoleTextAttribute(hConsole, 14);
	string name;
	string type;
	string status;
	string time;
	string mes[5];
	ifstream ifile;
	stringstream ss;
	ss << ide;
	string order = ss.str();
	int order1 = stoi(ch) - 1;
	stringstream ss1;
	ss1 << order1;
	ch = ss1.str();
	ifile.open("Mailbox/" + order + "/mail" + ch + ".m");
	getline(ifile, name);
	getline(ifile, type);
	getline(ifile, status);
	getline(ifile, time);
	for (int i = 0; i < 5; i++)
	{
		getline(ifile, mes[i]);
	}
	ifile.close();
	cout << endl;
	Animation::draw_border(44, color_cyan);
	cout << endl;
	Animation::colorize_text("\t\tFrom: ", 14);
	cout << name << endl;
	Animation::colorize_text("\t\tType: ", 14);
	cout << type << endl;
	Animation::colorize_text("\t\tStatus: ", 14);
	cout << status << endl;
	Animation::colorize_text("\t\tTime and Date: ", 14);
	cout << time << endl;
	Animation::draw_border(44, color_cyan);
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		Animation::colorize_text("\t\t" + mes[i], 14);
		cout << endl;
	}

	cout << endl;
	Animation::draw_border(44, color_cyan);
	Animation::frame_phrase("             0. Back                    ", color_cyan);
	Animation::draw_border(44, color_cyan);

	SetConsoleTextAttribute(hConsole, 15);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '0':
				mailbox_check(ide);
				break;
			}
		}
	}
}

void Customer::delete_all_mails(int ide)
{
	system("cls");
	ofstream ofile;
	string filename1;
	stringstream ss;
	ss << ide;
	string order = ss.str();
	string order1;

	ofile.open("Mailbox/" + order + "/c.dat");
	ofile << "0" << endl;
	ofile.close();
	cust[ide].message_status = "";
	cust[ide].message_type = "";
	cust[ide].sender_name = "";
	cust[ide].message_status = "";
	cust[ide].message_time = "";
	for (int j = 0; j < 5; j++)
	{
		cust[ide].answer[j] = "";
	}
	for (int i = 0; i < 100; i++)
	{
		stringstream ss;
		ss << i;
		order1 = ss.str();
		filename1 = "Mailbox/" + order + "/mail" + order1 + ".m";
		remove(filename1.c_str());	
	}

	cout << endl;
	Animation::draw_border(41, color_cyan);
	Animation::frame_phrase("                                     ", color_cyan);
	Animation::frame_phrase("    All messages has been deleted!   ", color_cyan);
	Animation::frame_phrase("                                     ", color_cyan);
	Animation::draw_border(41, color_cyan);
	Sleep(2000);
	menu();
}


//Log out customer

void Customer::log_out_customer()
{
	system("cls");
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
				user_exist = false;
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

