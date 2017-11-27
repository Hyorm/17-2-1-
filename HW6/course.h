#ifndef course_H
#define course_H

#include <iostream>
#include <string>

using namespace std;

//TODO:Make this class
class course{

	private:
		string name;
		string prof;
		string code;
		string week[3][5] = {{"x", "0", "0", "0", "0"}, {"x", "0", "0", "0", "0"}, {"x", "0", "0", "0", "0"}};
		int credits;
		int priority;

	public:
		course();

		~course();		

		void setName(string name);

		void setProf(string prof);

		void setCode(string code);

		void setWeek(int num, string (*week)[5]);

		void setCredits(string credits);

		void setPriority(int priority);

		void getInfo();

		string getName();

		string getProf();

		string getCode();

		string* getWeek(int num);

		int getCredits();

		int getPriority();
};

#endif
