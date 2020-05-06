#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Server.h"
#include <string>
using namespace std;

class Customer : 
	public Server
{
private:
	//Integral type
	int id;
	int idt;
	int amount[9];
	int stay_days;

	//Float type
	float price[9];
	float total_p = 0;
	float daily_cost;

	//Condition booleans
	bool user_exist = false;

	//Strings
	string user_login;
	string arrow[10];
	string food[9];
	string message[9];
	string complaint[50];
	string compliment[50];
	string answer[50];

protected:
	//Complaint & Compliments attributes
	string sender_name;
	string message_type;
	string message_time;
	string message_status;
	string sender_name_1;
	string sender_surname_1;
	string message_status_1;
	string message_line_count_1;
	string message_time_1;
	string message_type_1;
	string sender_name_2;
	string sender_surname_2;
	string message_status_2;
	string message_line_count_2;
	string message_time_2;
	string message_type_2;

public:
	//Menu
	void menu();
	void menu_comp_com();
	void make_order();
	void left_hotel();
	void delete_all_customers();
	void search_customer(string, string);
	void search_c(string);

	//I/O operations
	void write_info(int);
	void read_info();
	void read_messages();
	void get_all_messages();
	void display_customers();
	void delete_all_messages();

	//Log in/Log out functions
	void verification_customer();
	void log_out_customer();

	//Make an order
	void order_food();
	void display_food();
	void order_car();
	void order_service();

	//Compliment & Complaint
	void make_complaint();
	void make_compliment();
	int get_news_count();
	void read_message(string);
	void write_message(int, int);
	void mailbox_check(int);
	void delete_all_mails(int);
	void read_mail(string, int);

	//Left hotel
	void get_bill(int);

	//Support fucntions
	void update_data(int);
	float calculate_total(int);
	void calculate_debt(float);
	string get_current_time();
	float food_price(float, int);
	float total_price();

	//Overloaded input and output
	friend void operator<<(ostream &, Customer &);
	friend void operator>>(istream &, Customer &);
};

#endif

