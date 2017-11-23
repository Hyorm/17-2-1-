#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>

using namespace std;

//course structure declaration.
struct course {

	string name;
	int dayOfWeek1;
	int dayOfWeek2 = 0;
	int period;
	string prof;
	string code;
	int credits;

};

int selectMenu(string a, string b, string c);
string compareINT(int a);
void print_E(string arg);
int compare_toi(int a, int b);
int compare_tos(string a, string b);
void print_N();
course inputC(course a);
string scan();
void showTT(string tt[10][6]);
void print_J(string arg);
int compareDay(char a);
char scan_c();
void print_C(course a);
string print_Q(string a);
void print_s(string arg);

int main() {

	int menu, k = 1, l = 0, inputNum = 0, inputNum2 = 0;

	//Create a matrix containing default values.
	string timeTable[10][6] = { {"A", "M", "T", "W","T", "F"}, {"1","x","x","x","x","x" },{ "2","x","x","x","x","x" },{ "3","x","x","x","x","x" },{ "4","x","x","x","x","x" },{ "5","x","x","x","x","x" },{ "6","x","x","x","x","x" },{ "7","x","x","x","x","x" },{ "8","x","x","x","x","x" },{ "9","x","x","x","x","x" } };
	string timeTable2[10][6] = { { "B", "M", "T", "W","T", "F" },{ "1","x","x","x","x","x" },{ "2","x","x","x","x","x" },{ "3","x","x","x","x","x" },{ "4","x","x","x","x","x" },{ "5","x","x","x","x","x" },{ "6","x","x","x","x","x" },{ "7","x","x","x","x","x" },{ "8","x","x","x","x","x" },{ "9","x","x","x","x","x" } };
	course allWinter[20];
	course allWinter2[20];

	while (1) {

		//Divide two menus.
		menu = selectMenu("Choose one!", "1. Make Time Table", "2. Print List");
		int s1 = 0, s2 = 0, p1 = 0, p2 = 0;

		// The first option is to create a timetable by entering a lecture.
		if (compare_toi(menu, 1)) {
			//½Ã°£Ç¥
			course winter;
			showTT(timeTable);

			while (1) {
				while (1) {
					//Enter the structure of the lecture into the timetable.
					winter = inputC(winter);
					//If a wrong value is entered, it is input again.
					int c = 0;
					for (int i = 0; i < 10; i++) {
						for (int j = 1; j < 6; j++) {
							if (winter.name == timeTable[i][j]) {
								c++;
							}
						}
					}
					if (c == 0) break;
					print_E("This Course Name already exist..Try Again!");
					print_N();
				}

				allWinter[inputNum] = winter;
				inputNum++;

				//Compare the input structure with the A timetable.
				if (winter.dayOfWeek2 != 0) {
					if ((timeTable[winter.period][winter.dayOfWeek1 - 1] == "x") && (timeTable[winter.period][winter.dayOfWeek2 - 1] == "x")) {
						timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
						timeTable[winter.period][winter.dayOfWeek2 - 1] = winter.name;
						timeTable2[winter.period][winter.dayOfWeek1 - 1] = winter.name;
						timeTable2[winter.period][winter.dayOfWeek2 - 1] = winter.name;
					}
					else {

						//If it is already entered, ask if you want to replace it.
						print_N();
						print_E("This course time already exist..");
						showTT(timeTable);
						print_N();

						//If you do, put the name of the new lecture in A timetable.
						if ("Y" == print_Q("If you want to change?(Y/N)")) {
							for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 6; j++) {
									if (timeTable[winter.period][winter.dayOfWeek1 - 1] == timeTable[i][j]) {
										if ((j != winter.dayOfWeek1 - 1) || (i != winter.period)) {
											s1 = i;
											s2 = j;
										}
									}
								}
							}
							for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 6; j++) {
									if (timeTable[winter.period][winter.dayOfWeek2 - 1] == timeTable[i][j]) {
										if ((j != winter.dayOfWeek2 - 1) || (i != winter.period)) {
											p1 = i;
											p2 = j;
										}
									}
								}
							}
							if ((s1 != 0) || (p1 != 0)) {
								timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
								timeTable[winter.period][winter.dayOfWeek2 - 1] = winter.name;


								for (int i = 0; i < 20; i++) {
									if (allWinter[i].name == timeTable[s1][s2]) {
										allWinter2[inputNum2] = allWinter[i];
										inputNum2++;
										for (int j = i; j < inputNum; j++)
										{
											allWinter[j] = allWinter[j + 1];
										}
										inputNum--;
										break;
									}
								}

								timeTable[s1][s2] = "x";
								timeTable[p1][p2] = "x";

							}
							else {
								timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
								timeTable[winter.period][winter.dayOfWeek2 - 1] = winter.name;
							}
						}
						else {
							timeTable2[winter.period][winter.dayOfWeek1 - 1] = winter.name;
							timeTable2[winter.period][winter.dayOfWeek2 - 1] = winter.name;
						}
					}
				}
				else {
					if (timeTable[winter.period][winter.dayOfWeek1 - 1] != "x") {
						print_N();
						print_E("This course time already exist..");
						showTT(timeTable);
						print_N();
						if ("Y" == print_Q("If you want to change?(Y/N)")) {
							for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 6; j++) {
									if (timeTable[winter.period][winter.dayOfWeek1 - 1] == timeTable[i][j]) {
										if ((j != winter.dayOfWeek1 - 1) && (i != winter.period)) {
											s1 = i;
											s2 = j;
										}
									}
								}
							}
							if (s1 != 0) {
								timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
								for (int i = 0; i < 20; i++) {
									if (allWinter[i].name == timeTable[s1][s2]) {
										allWinter2[inputNum2] = allWinter[i];
										inputNum2++;
										for (int j = i; j < inputNum; j++)
										{
											allWinter[j] = allWinter[j + 1];
										}
										inputNum--;
										break;
									}
								}
								timeTable[s1][s2] = "x";
							}
							else
								timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
						}
						else {
							timeTable2[winter.period][winter.dayOfWeek1 - 1] = winter.name;
						}
					}
					else {
						timeTable[winter.period][winter.dayOfWeek1 - 1] = winter.name;
						timeTable2[winter.period][winter.dayOfWeek1 - 1] = winter.name;
					}
				}

				print_E("If you want more input? (Y/N)");
				string ans = scan();
				if (compare_tos(ans, "N"))break;
				if (compare_tos(ans, "n"))break;

			}

			print_E("If you want to break? (Y/N)");
			string ans = scan();
			if (compare_tos(ans, "Y"))break;
			if (compare_tos(ans, "y"))break;
		}

		//The second choice is to view the timetable and the list of lectures.
		else if (compare_toi(menu, 2)) {
			while (1) {

				//Divide two menus.
				print_E("Want Type!");
				print_E("A: Done Type");
				print_E("B: No choose Type");

				string ans = scan();

				//The first selection shows the completed timetable.
				if ("A" == ans) {
					showTT(timeTable);
					cout <<endl <<"code" << setw(20) << "title" << setw(20) << "day of Week" << setw(20) << "period" << setw(20) << "professor" << setw(20) << "credits" << endl;
					for (int i = 0; i < inputNum;i++) {
						print_C(allWinter[i]);
					}
					//Compares the input credits with the desired credits.
					cout << "Enter the credit you want to fill:" << endl;
					int f = stoi(scan());
					int z = 0;
					for (int i = 0; i < inputNum; i++) {
						z += allWinter[i].credits;
					}
					cout << "Your chosen credit is" << z << endl;
					if (f > z)
						cout << "You need "<< f-z<< " more credits!"<<endl;
					else if(f == z)
						cout << "Perfect credits!" << endl;
					else 
						cout << "You need to reduce the number of lectures by " << z - f << " credits.." << endl;
					break;
				}

				//The second option shows the values that did not fit in the completed timetable. 
				else if ("B" == ans) {
					showTT(timeTable2);
					cout << endl <<"code" << setw(20) << "title" << setw(20) << "day of Week" << setw(20) << "period" << setw(20) << "professor" << setw(20) << "credits" << endl;
					for (int i = 0; i < inputNum2; i++) {
						print_C(allWinter2[i]);
					}
					break;
				}
				else {
					print_E("Wrong Input..Try Again!");
					print_N();
				}
			}
			print_E("If you want to break? (Y/N)");
			string ans = scan();
			if (compare_tos(ans, "Y"))break;
			if (compare_tos(ans, "y"))break;
		}
		else {
			print_E("Wrong input.");
			print_N();
		}
	}


}

int selectMenu(string a, string b, string c) {

	string d;

	print_E(a);
	print_N();
	print_E(b);
	print_E(c);

	cin >> d;
	return stoi(d);

}

void print_E(string arg) {

	cout << arg << endl;

}

void print_J(string arg) {

	cout << arg ;

}

void print_s(string arg) {

	cout << setw(10) <<arg;

}

int compare_toi(int a, int b) {
	
	if (a == b)
		return 1;
	else
		return 0;

}

int compare_tos(string a, string b) {

	if (a == b)
		return 1;
	else
		return 0;

}

void print_N() {

	cout << endl;

}
string compareINT(int a) {

	switch (a) {
	case 2:
		return "Mon";
		break;

	case 3:
		return "Tue";
		break;

	case 4:
		return "Wed";
		break;

	case 5:
		return "Thu";
		break;

	case 6:
		return "Fri";
		break;

	}
}
int compareDay(char a) {

	switch (a) {
	case 'M':
		return 2;
		break;

	case 'T':
		return 3;
		break;

	case 'W':
		return 4;
		break;

	case 'H':
		return 5;
		break;

	case 'F':
		return 6;
		break;
	default:
		print_E("Wrong Input. Try Again!: ");
		return compareDay(scan_c());
		break;
	}
}

course inputC(course a) {

		print_E("Course Name: ");
		a.name = scan();

		print_E("Course Day Of Week (ex, monday => M, tuesday => T, wednesday => W, thursday => H, friday => F): ");

		a.dayOfWeek1 = compareDay(scan_c());
		if ("Y" == print_Q("This course has another day? (Y/N)")) {
			print_E("Course Another Day Of Week (ex, monday => M, tuesday => T, wednesday => W, thursday => H, friday => F): ");
			a.dayOfWeek2 = compareDay(scan_c());
		}
		while (1) {
			print_E("Course period: ");
			a.period = stoi(scan());
			if ((a.period <= 9) && (a.period > 0))
				break;
			print_E("Wrong Input. Try Again!");
		}

		print_E("Course Prof: ");
		a.prof = scan();
		print_N();

		print_E("Course Code: ");
		a.code = scan();
		print_N();

		print_E("Course Credits: ");
		a.credits= stoi(scan());
		print_N();

	return a;
}

string scan() {

	string a;

	cin >> a;

	return a;

}

char scan_c() {

	char a;

	cin >> a;

	return a;

}

void showTT(string tt[10][6]) {

	for (int j = 0; j < 10; j++) {
		print_N();
		for (int i = 0; i < 6; i++) {
			print_s(tt[j][i]);
		}
		print_N();
	}

}

void print_C(course allWinter) {

	cout << allWinter.code << setw(25) << allWinter.name << setw(17) << compareINT(allWinter.dayOfWeek1) << "," << compareINT(allWinter.dayOfWeek2) << setw(17) << allWinter.period << setw(17) << allWinter.prof << setw(17) << allWinter.credits << endl;
	print_N();
}

string print_Q(string a) {
	
	string b;

	print_N();
	print_E(a);
	
	b = scan();

	return b;
}
