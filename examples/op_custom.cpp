#include <iostream>
#include "math.h" 
using namespace std;

class Point {
    public:
    int x;
    int y;
    
    /*friend Point operator ^(Point &p, int power) {
        int x = pow(p.x, power);
        int y = pow(p.y, power);
        return {x, y};
    }*/
       
    Point operator ^(int power) {
        x = pow(x, power);
        y = pow(y, power);
        return {x, y};
    }
};

int main(){
Point p1 = {2, 3};
p1 = p1^3;
cout << p1.x<< ";" << p1.y << endl;
//p1.x is 8 and p1.y is 27
}