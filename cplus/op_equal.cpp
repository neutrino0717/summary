#include <iostream>
using namespace std;

struct Point {
    public:
    int x;
    int y;
    
    friend bool operator ==(Point &left, Point &right) {
        return (left.x == right.x) && (left.y == right.y);
    }
    /*
    friend bool operator !=(Point &left, Point &right) {
        return (left.x != right.x) || (left.y != right.y);
    }*/
    
    bool operator !=(Point &right) {
        return (x != right.x) || (y != right.y);
    }
};

int main(){
Point p1 = {1, 1};
Point p2 = {2, 2};
Point p3 = {1, 1};

 cout << ( p1 == p2 ) << endl;
//equal1 is 0
 cout << ( p1 == p3 ) << endl;
//equal2 is 1
 cout << ( p1 != p3 ) << endl;
//equal3 is 0
}