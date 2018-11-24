#include <iostream>
using namespace std;

int main()
{
    int age = 16;
    int score = 90;
    int grade = 80;

    if (age > 16 && age < 60 && grade > 50) {
        cout << "1 Accepted!" << endl;
    }
    if (age > 20 || score > 50) {
        cout << "2 Accepted!" << endl;
    }

    if ( !(age > 16) ) {
        cout << "Your age is less than 16" << endl;
    }

    return 0;
}
