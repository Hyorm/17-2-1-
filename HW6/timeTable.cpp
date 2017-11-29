#include <iostream>
#include <cstring>
#include <iomanip>
#include "course.h"
#include "courseSet.h"
#include "timeTable.h"

using namespace std;

		timeTable::timeTable(){}

		timeTable::~timeTable(){}

		string* timeTable::getSameList(){

			return this->sameList;

		}

		void timeTable::resetSet(){

			string newSet[10][6] = { {"S", "M", "T", "W","T", "F"}, {"1","x","x","x","x","x" },{ "2","x","x","x","x","x" },{ "3","x","x","x","x","x" },{ "4","x","x","x","x","x" },{ "5","x","x","x","x","x" },{ "6","x","x","x","x","x" },{ "7","x","x","x","x","x" },{ "8","x","x","x","x","x" },{ "9","x","x","x","x","x" } };
			for(int i = 0; i < 10; i++)
				for(int j =0; j<6; j++)
					time[i][j] = newSet[i][j];

		}

		void timeTable::setMax(int max){

			this->max = max;

		}

		void timeTable::setMin(int min){

			this->min = min;

		}

		int timeTable::getMax(){

			return this->max;

		}

		int timeTable::getNow(){

			return this->now;

		}

		int timeTable::getMin(){

			return this->min;

		}

		void timeTable::getTimeTable(){

			for (int j = 0; j < 10; j++) {

				cout<<endl;

				for (int i = 0; i < 6; i++) 
					cout<<setw(10)<<time[j][i];

				cout<<endl;
			}
		}

		void timeTable::setTimeTable(courseSet listSet){

			course* priority;

			for(int t = 0; t < 5; t++){

				priority = listSet.getPrioritySet(t);

				for(int i = 0; i<20; i++){

					if(priority[i].getName().length()<1){
						break;
					}
					
					string * get_week;
					string week[3][5];
				
					for(int n = 0; n < 3; n++){

						get_week = priority[i].getWeek(n);

						for(int q = 0; q<5;q++)
							week[n][q] = get_week[q];
						
					}
	
					if(max<now+priority[i].getCredits()){
						t=5;
						break;
					}

					int goNum = 0;
					int go = 0;
					int weekDay;
					for(int j = 0; j < 3; j++){
						if(week[j][0]=="x")break;
						if(week[j][0]=="M")weekDay = 1;
						else if(week[j][0]=="T")weekDay = 2;
						else if(week[j][0]=="W")weekDay = 3;
						else if(week[j][0]=="H")weekDay = 4;
						else if(week[j][0]=="F")weekDay = 5;

						for(int k = 1; k < 5; k++){

							if((atoi(week[j][k].c_str()))==0){
								goNum+=k-1;
								break;

							}
							if(time[atoi(week[j][k].c_str())][weekDay]=="x")
								go++;
						}
					}

					if(go==goNum){
						now += priority[i].getCredits();
						cout<<"Credits: "<<now<<endl;
						for(int j = 0; j < 3; j++){
							if(week[j][0]=="x")break;
							if(week[j][0]=="M")weekDay = 1;
							else if(week[j][0]=="T")weekDay = 2;
							else if(week[j][0]=="W")weekDay = 3;
							else if(week[j][0]=="H")weekDay = 4;
							else if(week[j][0]=="F")weekDay = 5;
						
							 for(int k = 1; k < 5; k++){
								if((atoi(week[j][k].c_str()))!=0){
									time[atoi(week[j][k].c_str())][weekDay]= priority[i].getName();
									list[listNum] = priority[i];
									listNum++;
								}
							}
						}
					}else if(week[0][0]!="x"){

						sameList[sameListNum] = time[atoi(week[1][1].c_str())][weekDay];
						sameListNum++;
						sameList[sameListNum] = priority[i].getName();
						sameListNum++;
					}
					if(min<now){
						i = 20;
						t = 5;
					}
				}
			}			
		}
