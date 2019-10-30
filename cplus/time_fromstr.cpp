#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
string stringDate = "1975-05-09 01:00";
tm tm;
istringstream stream(stringDate);
stream >> get_time(&tm, "%Y-%m-%d %H:%M");
time_t victoryDate  = mktime(&tm); 
cout << victoryDate << endl;
}