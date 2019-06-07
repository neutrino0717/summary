#include <iostream>
using namespace std;

class Point {
    public:
    int x;
    int y;
    
    friend bool operator >(Point &left, Point &right) {
        return left.x > right.x && left.y > right.y;
    }
    
    //friend bool operator <(Point &left, Point &right) {
       // return left.x < right.x && left.y < right.y;
    //}
    
        
    bool operator <(Point &right) {
        return this->x < right.x && this->y < right.y;
    }
};

int main(){
Point p1 = {1, 2};
Point p2 = {2, 3};

cout << (p1 > p2);
//b1 is 0
cout << (p1 < p2);
//b2 is 1
}