#include <iostream>
using namespace std; 
int main(){
char charA = 'A';
string stringA(2, charA);
cout << stringA << endl;

string str = "ABC";
charA = str[0];
//charA is 'A'
char charB = str[1];
//charB is 'B'
char charC = str[2];
//charC is 'C'

string charList = "";
for (char c : str) {
    charList += string(1, c) + ";";
}
cout << charList << endl;
}