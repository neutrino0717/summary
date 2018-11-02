#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "bool *: " << sizeof(bool*) << endl;
    cout << "int *: " << sizeof(int*) << endl;
    cout << "string: " << sizeof(string) << endl;
    string s = "I am C++"; cout << "string s: " << sizeof(s) << endl;

    cout << "bool: " << sizeof(bool) << endl;
    bool b = true; cout << "bool b: " << sizeof(b) << endl;
    cout << "char: " << sizeof(char) << endl;
    char c = 'S'; cout << "char c: " << sizeof(c) << endl;
    cout << "int: " << sizeof(int) << endl;
    int i = 50; cout << "int i: " << sizeof(i) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "unsigned long int: " << sizeof(unsigned long int) << endl;

    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    double myArr[10]; cout << "double myArr[10]: " << sizeof(myArr) << endl;

    
    return 0;
}
