#include <iostream>
#include <string>
#include "course.h"

using namespace std;

		course(){};

		~course(){};

		void setName(string name){

			this->name = name;

		}

		void setProf(string prof){
		
			this->prof = prof;

		}

		void setCode(string code){

			this->code = code;

		}

		void setDayOfWeek(int num, string week){

			this->dayOfWeek[num] = week;

		}


		void setPeriod(int num, int period){

			this->period[num] = preriod;

		}

		void setCredits(int credits){

			this->credits = credits;

		}

		void setPriority(int priority){
	
			this->priority = priority;

		}

		void getInfo(){

			cout<<setw(17)<<this->name<<setw(11)<<this->prof<<setw(6)<<dayOfWeek[0]<<","<<dayOfWeek[1]<<"/"<<this->period[0]<<","<<this->period[1]<<<<setw(8)<<this->credit<<setw(6)<<this->code<<endl;

		}

		string getName(){

			return this->name;

		}

		string getProf(){

			return this->prof;

		}

		string getCode(){

			return this->code;

		}

		string getDayOfWeek(int num){

			return this->dayOfWeek[num];

		}

		int getPeriod(){

			return this->period;

		}

		int getCredits(){

			return this->credits;

		}

		int getPriority(){

			return this->priority;

		}
