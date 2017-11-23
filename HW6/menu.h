#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

using namespace std;

class menu{

	private:
		static string arg[15];
		int argNum = 0;
		int argNumWeek = 6;
		int parsArg;
		int parsArg2;
		string line;

	public:
		menu();

		~menu();

		void getMenu();
	
		string *getArg();
	
		void setArg();

};
#endif
