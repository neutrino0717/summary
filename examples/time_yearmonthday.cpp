#include <iostream>
using namespace std;

int main (){
	time_t now = time(0);
	tm tm = *localtime(&now);
	int year = tm.tm_year + 1900;
	int month = tm.tm_mon + 1;
	int day = tm.tm_mday;
	int hour = tm.tm_hour;
	int minute = tm.tm_min;
	int second = tm.tm_sec;
	int dayOfWeek = tm.tm_wday;
	cout << year << ":" << month  << ":" << day << ":" << hour << ":" << minute << ":" << second << endl;

	tm={2, 30, 22, 17, 7-1, 1975-1900};
	year = tm.tm_year + 1900;
	month = tm.tm_mon + 1;
	day = tm.tm_mday;
	hour = tm.tm_hour;
	minute = tm.tm_min;
	second = tm.tm_sec;
	dayOfWeek = tm.tm_wday;
	cout << year << ":" << month  << ":" << day << ":" << hour << ":" << minute << ":" << second << endl;

}
