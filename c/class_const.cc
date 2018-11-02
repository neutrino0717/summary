#include <iostream>
using namespace std;
const int x = 42; //constant variables must be initialized at the time of creation

class MyClass
{
    public:
        void myPrint() const;//A constant object can't call regular functions. Hence, for a constant object to work you need a constant function. 
};

void MyClass::myPrint() const {
    cout <<"Hello"<<endl;
}

int main() {
    const MyClass obj; //for classes, this initialization is done via constructors
    obj.myPrint(); //Once a const class object has been initialized via the constructor, you cannot modify the object's member variables. 
}
