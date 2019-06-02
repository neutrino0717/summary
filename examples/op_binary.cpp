#include <iostream>
using namespace std;
int main(){

struct Point {
    public:
    int x;
    int y;
    
    Point operator +(const Point & p){
        return {x + p.x, y + p.y};
    }
    
    void operator +=(Point p){
        x += p.x;
        y += p.y;
    }
};

Point p1 {1, 1};
Point p2 {2, 2};
Point p3 = p1 + p2;
cout << p3.x <<"," << p3.y <<endl;
//p3.x is 3 and p3.y is 3
p3 += {3, 5};
cout << p3.x <<"," << p3.y <<endl;
//p3.x is 6 and p3.y is 8
}