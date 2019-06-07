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

int main(){}
//Array of integer
int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19 };

//Array of string
string gameList[] { "soccer", "hockey", "basketball" };

//Array of Employee class
Employee employees[] {
    Employee("Anton", "Pavlov"),
    Employee("Elena", "Kirienko")
};
