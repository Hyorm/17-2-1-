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
		string dayOfWeek[2] = {"x"};
		int period;
		int credits;
		int priority[2];

	public:
		course();

		~course();		

		void setName(string name);

		void setProf(string prof);

		void setCode(string code);

		void setDayOfWeek(int num, string week);

		void setPeriod(int num, int period);

		void setCredits(int credits);

		void setPriority(int priority);

		void getInfo();

		string getName();

		string getProf();

		string getCode();

		string getDayOfWeek(int num);

		int getPeriod();

		int getCredits();

		int getPriority();
};

#endif
