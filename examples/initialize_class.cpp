#include <iostream>
using namespace std;
class Phone {
    public:
    string model;
    /*
    Phone(string model) {
        this->model = model;
    }
    
    Phone(){}*/
};

class Employee {
    public:
    string firstName;
    string lastName;
    Phone personalPhone;
  /*  construtor
    Employee(string firstName, string lastName, Phone phone) {
        this->firstName = firstName;
        this->lastName = lastName;
        personalPhone = phone;
    }*/
};

int main(){
    /*need constructor
Phone nokiaPhone("Nokia 6610");
Employee kim("Victorya", "Kim",  Phone("iPhone 5"));*/

Phone nokiaPhone {"Nokia 6610"};
Phone iPhone5 {"iPhone 5"};
Employee kim {"Victorya", "Kim", iPhone5};

    
}
