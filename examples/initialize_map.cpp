#include <iostream>
#include <map>
#include <set>
using namespace std;

class Employee {
    public:
    string FirstName;
    string LastName;
/*
        Employee(string firstName, string lastName)
    {
        FirstName = firstName;
        LastName = lastName;
    }*/
};
//Dictionary<String, String>
map<string, string> languages = {
    {"ru", "russian"},
    {"en", "english"}
};

//Dictionary<Int, String>
map<int, string>  numbers {
    {1, "one"}, {2, "two"}, {3, "three"}
};

//Dictionary<Int, Employee>
map<int, Employee> employees {
/* {1, Employee("Anton", "Pavlov")},
    {2, Employee("Elena", "Kirienko")}*/ 
    {1, Employee{"Anton", "Pavlov"}},
    {2, Employee{"Elena", "Kirienko"}}
};

set<int> intHashSet = { 2, 3, 5, 7, 11, 13, 17, 19 };
int main(){}