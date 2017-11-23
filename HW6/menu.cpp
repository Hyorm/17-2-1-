#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

		menu(){}

		~menu(){}

		void getMenu(){

			cout << "  =============== Available Commend & Format ===============" << endl << endl<<endl; 
			cout << "  1. INSERT Code; Course; Professor; Day; Period; Credit"<<endl;
			cout << "     (If you have another day or period, you can use this form: Day1/Day2; Period1/Period2/Period3)"<<endl;
			cout << "     (You can add up to 4 items separated by /)"<<endl<<endl;
			cout << "  2. Make maximum_credits; minimum credits"<<endl<<endl;
			cout << "  3. PRINT" <<endl<<endl;
			cout << "  4. SAVE new_filename.txt" <<endl<<endl;
			cout << "  5. EXIT"<<endl<<endl;
			cout << "  6. README"<<endl<<endl;
			cout << "  =========================================================="<<endl<<endl;
			cout << "  >>";

			getline(cin, this->line);
		}
	
		string *getArg(){

			return this->arg;

		}
	
		void setArg(){

			while(1){

				if (argNum == 0) {
					parsArg = this->line.find(" ");

					this->arg[argNum] = this->line.substr(0, parsArg);

					this->line.erase(0, parsArg+1);

					argNum++;

				}
				else{

					if (this->line.length() > 0) {

						parsArg = this->line.find(";"); 
			
						if(parsArg == -1){

							this->arg[argNum] = this->line;

							break;

						}

						parsArg2 = this->line.find("/");

						if((parsArg2!=-1)&&(parsArg>parsArg2)){
					
							this->arg[argNumWeek] = this->line.substr(0, parsArg2);

							this->line.erase(0, parsArg2+1);

							argNumWeek++;
	
							this->arg[14]=argNumWeek-6;

						}
						else{

							this->arg[argNum] = this->line.substr(0, parsArg);
	
							this->line.erase(0, parsArg+2);
	
							argNum++;
						}
					}
					else break;
				}
			}
		}

