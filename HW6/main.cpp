#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "course.h"
#include "courseSet.h"
#include "timeTable.h"

using namespace std;

void getMenu();
string (*getArg(string line))[5];

int main(){

	courseSet newCart = courseSet();

	timeTable newTable = timeTable();

	int exit = 1;

	int sameNum = 0;

	string * same;

	while(exit){

		string (*arg)[5];

		string line;

		getMenu();

		getline(cin, line);

		arg=getArg(line);

		char n = arg[0][0][0];

		string sF;

		switch(toupper(n)){

		case 'I':	sF = newCart.setCourseSet(arg);
				
				if(sF == "S") cout << "Insert Success"<<endl<<endl;
				else cout << "Insert Fail"<<endl<<endl;
				break;

		case 'D':	newCart.deleteCourse(arg[0][1]);
				newTable.resetSet();	
				break;

		case 'M':	newTable.setMax(atoi(arg[0][1].c_str()));
				newTable.setMin(atoi(arg[0][2].c_str()));
				newTable.setTimeTable(newCart);
				newTable.getTimeTable();

				same = newTable.getSameList();
				sameNum = 0;
				while(same[sameNum].length()>0){
					cout<<"Overlap: "<<same[sameNum]<<"/"<<same[sameNum+1]<<endl;
					sameNum += 2;
				}
				break;				

		case 'P':	if(arg[0][1][0]=='T'){
					newTable.getTimeTable();
					break;
				}else if(arg[0][1][0]=='C'){
					int num = newCart.getCourseNum();
					for(int i = 0; i< num;i++)
						newCart.getCourseSet(i).getInfo();
				}else
					cout << "Wrong Input. Try Again."<<endl<<endl;
				break;

		case 'S':

		case 'E':	exit = 0;
				break;

		case 'R':	break;

		}
	}
}
	
void getMenu(){

	cout << "  =============== Available Commend & Format ===============" << endl << endl<<endl;  
	cout << "  1. INSERT Code; Course; Professor; Day=Period; Credit"<<endl; 
	cout << "     (If you have another day or period, you can use this form: "<<endl<<"     Day1=Period1/Period2/Period3, Day2=Period1/Period2)"<<endl; 
	cout << "     (You can add up to 3 items separated by /)"<<endl<<endl;
	cout << "  2. Delete code" <<endl<<endl;
	cout << "  3. Make maximum_credits; minimum credits"<<endl<<endl; 
	cout << "  4. PRINT type"<<endl<<"     (type: TimeTable or CourseCart)" <<endl<<endl; 
	cout << "  5. SAVE new_filename.txt"<<endl<<endl; 
	cout << "  6. EXIT"<<endl<<endl; 
	cout << "  7. README"<<endl<<endl; 
	cout << "  =========================================================="<<endl<<endl; 
	cout << "  >>"; 
}

string (*getArg(string line))[5]{

	static string arg[4][5] = {{"x", "0", "0", "0", "0"}, {"x", "0", "0", "0", "0"}, {"x", "0", "0", "0", "0"}, {"x", "0", "0", "0", "0"}};

	int argNum = 0, parsArg, parsArg2, parsArg3, argNum2=0, argNum22=0, repeat=1;
 
	while(1){ 

		if (argNum == 0) { 
			parsArg = line.find(" "); 

			arg[0][argNum] = line.substr(0, parsArg); 
			line.erase(0, parsArg+1); 
			argNum++; 
 
		} 
		else{ 

			if (line.length() > 0) { 
 
				parsArg = line.find(";");  
		 
				if(parsArg == -1){ 
 
					arg[0][argNum] = line;
					break; 
				}
		
				parsArg2 = line.find("=");

				if((parsArg2!=-1)&&(parsArg>parsArg2)){

					while(repeat){

						argNum2++;	
						argNum22 = 0;
						parsArg2 = line.find("=");
						arg[argNum2][argNum22] = line.substr(0, parsArg2);
						argNum22++;
						line.erase(0, parsArg2+1);
							
						while(repeat){

							parsArg3 = line.find(",");

							if(parsArg3==-1)parsArg3 = 50;
						
							parsArg2 = line.find("/");

							parsArg = line.find(";");

							if((parsArg2!=-1)&&(parsArg>parsArg2)&&(parsArg3>parsArg2)){

								arg[argNum2][argNum22]=line.substr(0, parsArg2);
								line.erase(0, parsArg2+1);
								argNum22++;
								
							}else{
								
								if(parsArg3!=50){
									arg[argNum2][argNum22]=line.substr(0, 1);
									line.erase(0, 3);

									break;
								}
								else{
									parsArg = line.find(";");
									arg[argNum2][argNum22]=line.substr(0, parsArg);
									line.erase(0, parsArg+2);
									repeat = 0;
								}
							}
						}
					}				
				}
				else{
					arg[0][argNum] = line.substr(0, parsArg); 
					line.erase(0, parsArg+2); 
					argNum++; 
				}	
			} 
	 
			else break; 
		} 
	}	
	return arg;
}

