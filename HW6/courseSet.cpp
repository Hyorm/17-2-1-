#include <iostream>
#include <string>
#include "courseSet.h"
#include "course.h"

using namespace std;

		courseSet::courseSet(){}

		courseSet::~courseSet(){}

		course courseSet::getCourseSet(int num){

			return this->list[num];

		}

		int courseSet::getCourseNum(){
			
			return this->listNum;

		}

		void courseSet::deleteCourse(string code){

			for(int i=0;i<listNum;i++){

				if(list[i].getCode()==code){
					
					for(int j = i; j< listNum; j++)
						list[i] = list[i+1];
				
					listNum--;
					break;
				}
			}

			cout<<"Delete!"<<endl;
		}

		course* courseSet::getPrioritySet(int num){

			static course prioritySet[20];

			int setNum = 0;

			for(int i=0;i<listNum;i++){

				if(list[i].getPriority()==num){

					prioritySet[setNum] = list[i];
					setNum++;
				}
			}
			return prioritySet;
		}

		string courseSet::setCourseSet(string (*arg)[5]){

			int day, per, cre;
			string yORn;

			if(listNum>30){

				cout<<"Cart was full...";

				return "F";
			}

//TODO:SET CODE
			if(listNum==0)
				list[listNum].setCode(arg[0][1]);
			
			for(int i=0;i<listNum;i++){
			
				if(list[i].getCode()==arg[0][1]){

					cout<<"This course already exists."<<endl;
	
					return "F";
				}
				else{

					list[listNum].setCode(arg[0][1]);
				}
			}
//TODO:SET NAME
			list[listNum].setName(arg[0][2]);
//TODO:SET PROF
			list[listNum].setProf(arg[0][3]);
//TODO:SET WEEK		
			list[listNum].setWeek(0, arg);

			list[listNum].setWeek(1, arg);

			list[listNum].setWeek(2, arg);
//TODO:CRED		
			list[listNum].setCredits(arg[0][4]);		

//TODO:SET PRIORITY
			int repeat = 1;

			while(repeat){
				cout<<endl<<"Is this course a major?(Y/N)";

				cin>>yORn;

				if(yORn=="Y"){

					while(repeat){

						cout<<endl<<"Do you really have to take this course this semester?(Y/N)";
						cin>>yORn;

						if(yORn=="Y"){

							list[listNum].setPriority(1);

							repeat=0;

						}
						else if(yORn=="N"){

							list[listNum].setPriority(2);

							repeat=0;

						}
						else
							cout<<endl<<"Wrone Input. Try Again.";
					}
				}
				else if(yORn=="N"){
					while(repeat){

						cout<<endl<<"Is this course in practical English?(Y/N)";

						cin>>yORn;

						if(yORn=="Y"){

							while(repeat){

								cout<<endl<<"Do you really have to take this course this semester?(Y/N)";
								cin>>yORn;

								if(yORn=="Y"){
									list[listNum].setPriority(3);
									repeat=0;
								}
								else if(yORn=="N"){
									list[listNum].setPriority(4);
									repeat=0;
								}
								else
									cout<<endl<<"Wrone Input. Try Again.";
							}
						}
						else if(yORn=="N"){

							list[listNum].setPriority(5);

							repeat = 0;
						}
						else
							cout<<endl<<"Wrone Input. Try Again.";
					}
				}else
					cout<<endl<<"Wrone Input. Try Again.";
			}

			listNum++;

			return "S";
		}




