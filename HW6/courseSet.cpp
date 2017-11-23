#include <iostream>
#include <string>
#include "courseSet.h"
#include "course.h"

using namespace std;

		courseSet(){}

		~courseSet(){}

		course getCourseSet(int num){

			return this->list[num];

		}

		void setCourseSet(){

			if(listNum>30){

				cout<<"Cart was full...";

				break;
			}

//TODO:SET COURSE

//TODO:SET PRIORITY
			repeat = 1;

			while(repeat){
				cout<<endl<<"Is this course a major?(Y/N)";

				cin>>yORn;

				if(yORn=="Y"){

					while(repeat){

						cout<<endl<<"Do you really have to take this course this semester?(Y/N)";

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
		}




