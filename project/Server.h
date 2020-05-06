#pragma once

#ifndef SERVER_H
#define SERVER_H

#include "Controller.h"
#include <string>
using namespace std;

class Server :
	public Controller
{
protected:
	string n_order;

	//Customer information attributes
	string customer_name;
	string customer_surname;
	string customer_oc;
	string customer_login;
	string customer_password;
	string room_type;
	string customer_age;
	string reg_year;
	string reg_month;
	string reg_day;
	string debt;

public:
	void menu();
	void verification_admin();
	void log_out_admin();
	void add_customer();
	void search_customer();
	void display_customer();
	void display_all();
	void delete_customer();
	void display_orders();
	void display_comp_com();
	void room_details();
};

#endif
