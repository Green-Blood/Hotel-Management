#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
using namespace std;

class Controller
{
protected:
	string admin_password = "admin";
	string admin_login = "admin";

public:
	int num;
	void main_menu();
	void log_in();
	void about();
	void verification_manager();
};

#endif
