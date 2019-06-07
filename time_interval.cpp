#include <iostream>  
using namespace std;

int main(){
int year = 1975;
int month = 7;
int day = 17;
tm tm {0, 0, 0, day, month-1, year-1900};

time_t now = time(0);

struct tm tmNow = *localtime(&now);

int years = tmNow.tm_year - tm.tm_year;
//years is 71
time_t victoryDate = mktime(&tm);
long days = (now - victoryDate) / 86400;

//days is 25942
long minutes = tmNow.tm_min - tm.tm_min;
//minutes is 51
cout << "years:" << years << endl;
cout << "days:" << days  << endl;
cout << "days:" << (tmNow.tm_mday - tm.tm_mday) << endl;
cout << "minutes:" << minutes << endl;
}