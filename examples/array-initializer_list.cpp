#include <iostream>
using namespace std;

class Employee {
    public:
        string FirstName;
        string LastName;

        Employee(string firstName, string lastName)
        {
            FirstName = firstName;
            LastName = lastName;
        }
};

//Array of Employee class by constructor
Employee employees[] {
    Employee("Anton", "Pavlov"),
    Employee("Elena", "Kirienko")
};


//Array of Employee class by initializer list
Employee employees2[] {
    {"Anton", "Pavlov"},
    {"Elena", "Kirienko"}
};

//Array of integer
int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19 };

//Array of string
string gameList[] { "soccer", "hockey", "basketball" };

int main(){}
