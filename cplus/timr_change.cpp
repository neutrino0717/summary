#include <iostream>
using namespace std;

int main (){
time_t now = time(0);
time_t tmr1 = now + 86400;

tm  tm = *localtime(&now);
tm.tm_mday += 1;
time_t tmr2 = mktime(&tm);
cout << tmr1 << '\n' << tmr2 << endl;
cout << (tmr1 == tmr2 ) << endl;

tm = *localtime(&now);
tm.tm_mon += 1;
time_t nextMonth = mktime(&tm);

tm = *localtime(&now);
tm.tm_year += 1;
time_t nextYear = mktime(&tm);
}