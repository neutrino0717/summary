#include <iostream>
using namespace std;

int main(){
string str = "Lower and upper";

string lower = str;
transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
//lower is "lower and upper"
cout << lower << endl;

string upper = str;
std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
//upper is "LOWER AND UPPER"
cout << upper << endl;

}