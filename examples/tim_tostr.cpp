#include <iostream>
using namespace std;

int main (){
time_t now = time(0);
char shortStyle[20];
strftime(shortStyle, sizeof(shortStyle),
    "%D %H:%M %p", localtime(&now));
cout << shortStyle << endl;
//shortStyle is "05/18/16 May:48 AM"

char customStyle[20];
strftime(customStyle, sizeof(customStyle),
    "%Y-%m-%d", localtime(&now));
//customStyle is "2016-05-18" 
cout << customStyle << endl;

strftime(shortStyle, sizeof(shortStyle),
    "%Y-%m-%d", localtime(&now));
cout << shortStyle << endl;

}
