#include <iostream>
#include <sstream>
using namespace std;

int main(){
bool sunIsStar = true;

//the first method
stringstream stream;
stream  <<boolalpha<< sunIsStar;
string str = stream.str();
cout << str <<'\n';

//the second method
str = sunIsStar ? "true" : "false";
cout << str <<'\n';

//str is "true"
}