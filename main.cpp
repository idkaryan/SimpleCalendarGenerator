#include <iostream>
#include <string>
#include <iomanip>

const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;

const int DAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

using namespace std;

void calcDay(string& mon, int year);
int assignCurMonth(string &mon);
int assignDaysInCurMonth(int mon, int year);
bool leapCheck(int year);
int weekProgress(int curDay, int daysToProgress);
int calcFirstDayOfYear(int year);
int calcFirstDayOfMonth(int firstDayOfYear, int month, bool isLeapYear);
void printCalender(int firstDayOfMonth, string& mon, int year, int month);
string getMonthString(string& mon);

int main(int argc, char** argv) {
	string month = "";
	int year = 0;

	if (argc < 3) {
		cout << "Use the first 3 characters for entering months.\n";
		cout << "e.g : jan , feb, mar..\n\n";
		cout << "Month : ";
		getline(cin, month);
		
		cout << "Year  : ";
		while (!(cin >> year)) {
			cout << "That's not a valid year.\n";
			cin.clear();
			cin.ignore(9999, '\n');
			cout << "Year : ";
		}
	}
	else {
		month = argv[1];
		year = (int)argv[2];
	}

	if (year < 1960) {
		cout << "Calender ranges from 1960 -> forever. Gomenasai! :(" << endl;
		cout << "Check another year, pweaase? : ";
		cin >> year;
		cin.clear();
		cin.ignore(9999, '\n');
		
		cout << "Month? : ";
		getline(cin, month);
	}

	calcDay(month, year);

	return 0;
}

void calcDay(string& mon, int year) {
	int curMonth = 0;
	int daysInCurMonth = 0;
	int firstDayOfYear = 0;
	int firstDayOfMonth = 0;
	bool isLeapYear = leapCheck(year);

	curMonth = assignCurMonth(mon);

	daysInCurMonth = assignDaysInCurMonth(curMonth, year);

	firstDayOfYear = calcFirstDayOfYear(year);
	
	firstDayOfMonth = calcFirstDayOfMonth(firstDayOfYear, curMonth, isLeapYear);

	printCalender(firstDayOfMonth, mon, year, curMonth);
}

string getMonthString(string& mon) {
	if (mon == "jan")
		return "January";
	else if (mon == "feb")
		return "February";
	else if (mon == "mar")
		return "March";
	else if (mon == "apr")
		return "April";
	else if (mon == "may")
		return "May";
	else if (mon == "jun")
		return "June";
	else if (mon == "jul")
		return "July";
	else if (mon == "aug")
		return "August";
	else if (mon == "sep")
		return "September";
	else if (mon == "oct")
		return "October";
	else if (mon == "nov")
		return "November";
	else if (mon == "dec")
		return "December";
	else {
		cout << "Invalid Input" << endl;
		exit(1);
	}
}

void printCalender(int firstDayOfMonth, string& mon, int year, int month) {
	int totalMonthDays = DAYS[month - 1];
	if (totalMonthDays == 28 && leapCheck(year)) {
		totalMonthDays += 1;
	}

	cout << "\n";
	cout << "     " << getMonthString(mon) << " " << year << endl;

	cout << "Su Mo Tu We Th Fr Sa" << endl;
	
	for (int i = 1; i < firstDayOfMonth; i++)
		cout << "   ";
	
	for (int i = 1; i <= totalMonthDays; i++) {
		cout << setw(2) << i << " ";
		if ((firstDayOfMonth % 7 == 0)) {
			cout << "\n";
		}
		firstDayOfMonth++;
		/*if ((firstDayOfMonth % 7 == 0) && (i + 1 <= DAYS[month - 1])) {
			i++;
			cout << setw(2) << i << "\n";
			firstDayOfMonth++;
		}*/
	}

	cout << "\n\n ~idkaryan@gmail.com (c) 2016\n\n";
	cout << "Enter any key to exit...";
	char z;
	cin >> z;
}

int calcFirstDayOfMonth(int firstDayOfYear, int month, bool isLeapYear) {
	int differenceInDays = 0;
	int temp_Month = 1;
	int i = 0;
	while (temp_Month < month) {
		differenceInDays += DAYS[i];

		if (i == 1 && isLeapYear) {
			differenceInDays++;
		}

		temp_Month++;
		i++;
	}
	int daysToProgress = differenceInDays % 7;
	int firstDayOfMonth = weekProgress(firstDayOfYear, daysToProgress);
	return firstDayOfMonth;
}

int calcFirstDayOfYear(int year) {
	int referenceYear = 1960;
	int referenceYearFirstDay = 6;
	
	int temp_year = referenceYear;
	long long differenceInDays = 0;
	
	while (temp_year < year) {
		differenceInDays += 365;
		if (leapCheck(temp_year)) {
			differenceInDays += 1;
		}
		temp_year++;
	}
	int firstDayOfYear = weekProgress(referenceYearFirstDay, differenceInDays);
	return firstDayOfYear;
}

int weekProgress(int curDay, int daysToProgress) {
	int dayNames[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int futureDay = daysToProgress % 7;
	futureDay += curDay;
	if (futureDay > 7) {
		futureDay -= 7;
	}
	return futureDay;
}

int assignCurMonth(string &mon) {
	int curMonth = 0;

	if (mon == "jan")
		curMonth = JAN;
	else if (mon == "feb")
		curMonth = FEB;
	else if (mon == "mar")
		curMonth = MAR;
	else if (mon == "apr")
		curMonth = APR;
	else if (mon == "may")
		curMonth = MAY;
	else if (mon == "jun")
		curMonth = JUN;
	else if (mon == "jul")
		curMonth = JUL;
	else if (mon == "aug")
		curMonth = AUG;
	else if (mon == "sep")
		curMonth = SEP;
	else if (mon == "oct")
		curMonth = OCT;
	else if (mon == "nov")
		curMonth = NOV;
	else if (mon == "dec")
		curMonth = DEC;
	else {
		cout << "Invalid input";
		exit(1);
	}
	return curMonth;
}

int assignDaysInCurMonth(int mon, int year) {
	
	bool isLeapYear = leapCheck(year);

	int days = 0;
	switch (mon) {
	case JAN:
		days = DAYS[0];
		break;
	case FEB:

		if (isLeapYear)
			days = DAYS[1] + 1;
		else 
			days = DAYS[1];
		
		break;
	case MAR:
		days = DAYS[2];
		break;
	case APR:
		days = DAYS[3];
		break;
	case MAY:
		days = DAYS[4];
		break;
	case JUN:
		days = DAYS[5];
		break;
	case JUL:
		days = DAYS[6];
		break;
	case AUG:
		days = DAYS[7];
		break;
	case SEP:
		days = DAYS[8];
		break;
	case OCT:
		days = DAYS[9];
		break;
	case NOV:
		days = DAYS[10];
		break;
	case DEC:
		days = DAYS[11];
		break;
	}
	return days;
}

bool leapCheck(int year) {
	if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) {
		return true;
	}
	else {
		return false;
	}
}