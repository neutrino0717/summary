#include <iostream>
using namespace std;

int main()
{
    int age = 42;
    switch (age) {
        case 16:
            cout << "Too young";
            break;
        case 42:
            cout << "Adult";
            break;
        case 70:
            cout << "Senior";
            break;
        default:
            cout << "This is the default case";
    }

    cout << "\n-------- if break is forgot, will fall through ----------\n";
    age = 42;
    switch (age) {
      case 16:
        cout << "Too young" << endl;
      case 42:
        cout << "Adult" << endl;    //without break, fall-through
      case 70:
        cout << "Senior" << endl;
      default:
        cout <<"This is the default case" << endl;
    } 
   return 0;
}
