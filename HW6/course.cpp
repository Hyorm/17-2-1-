#include <iostream>
#include <string>
#include <iomanip>
#include "course.h"

using namespace std;

		course::course(){};

		course::~course(){};

		void course::setName(string name){

			this->name = name;

		}

		void course::setProf(string prof){
		
			this->prof = prof;

		}

		void course::setCode(string code){

			this->code = code;

		}

		void course::setWeek(int num, string (*week)[5]){

			this->week[num][0] = week[num+1][0];
			this->week[num][1] = week[num+1][1];
			this->week[num][2] = week[num+1][2];
			this->week[num][3] = week[num+1][3];
			this->week[num][4] = week[num+1][4];

		}

		void course::setCredits(string credits){

			this->credits = atoi(credits.c_str());

		}

		void course::setPriority(int priority){
	
			this->priority = priority;

		}

		void course::getInfo(){

			cout<<setw(17)<<this->name<<setw(11)<<this->prof<<setw(6)<<this->week[0][0]<<","<<this->week[1][0]<<","<<this->week[2][0]<<setw(6)<<this->credits<<setw(6)<<this->code<<endl;

		}

		string course::getName(){

			return this->name;

		}

		string course::getProf(){

			return this->prof;

		}

		string course::getCode(){

			return this->code;

		}

		string* course::getWeek(int num){

			return this->week[num];

		}

		int course::getCredits(){

			return this->credits;

		}

		int course::getPriority(){

			return this->priority;

		}
