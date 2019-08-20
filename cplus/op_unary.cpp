#include <iostream>
using namespace std;

struct Point {
    public:
        int x;
        int y;
        // prefix ++, myview:
        Point & operator ++() {
            x++;
            y++;
            cout << "in prefix ++\n";
            return *this;
        }

        // postfix ++
        Point operator ++(int) {
            Point result = {x, y};
            ++(*this);
            cout << "in postfix ++\n";
            return result;
        }

        friend Point operator -(Point &p) {
            return {-p.x, -p.y};
        }
};

int main(){
    Point p = {1, 1};
    p++;
    cout << p.x <<","<< p.y << endl;
    //p3.x is 2 and p3.y is 2
    ++p;
    cout << p.x <<","<< p.y << endl;
    //p3.x is 3 and p3.y is 3
    p = -p;
    cout << p.x <<","<< p.y << endl;
    //p3.x is -3 and p3.y is -3
    cout << "read this: https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading.\n";
}
