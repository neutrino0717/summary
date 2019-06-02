#include <iostream>
using namespace std; 

int main(){
//to int
string strNumber = "42";
int number = stoi(strNumber);
cout << number << endl;
//to Double and Float
string strPi = "3.14";
float pi = stod(strPi);
cout << strPi << endl;
string strExp = "2.71828";
double exp = stod(strExp);
cout << exp << endl;
//replacement of non-standard delimiter
std::string strHalf = "0,5";
size_t index = strHalf.find(",", 0);
strHalf.replace(index, 1, ".");
double half = std::stod(strHalf);
cout << half << endl;
}
