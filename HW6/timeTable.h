#ifndef timeTable_H
#define timeTable_H

#include <iostream>
#include <string>
#include "course.h"
#include "courseSet.h"

using namespace std;

class timeTable{

	private:

		string time[10][6] = { {"S", "M", "T", "W","T", "F"}, {"1","x","x","x","x","x" },{ "2","x","x","x","x","x" },{ "3","x","x","x","x","x" },{ "4","x","x","x","x","x" },{ "5","x","x","x","x","x" },{ "6","x","x","x","x","x" },{ "7","x","x","x","x","x" },{ "8","x","x","x","x","x" },{ "9","x","x","x","x","x" } };
		int max, min, now = 0;

		course list[30];

		int listNum = 0;

		string sameList[30];

		int sameListNum = 0;
	public:

		timeTable();

		~timeTable();

		string* getSameList();

		void resetSet();

		void setMax(int max);

		void setMin(int min);

		int getMax();

		int getNow();

		int getMin();

		void getTimeTable();

		void setTimeTable(courseSet listSet);
};
#endif
