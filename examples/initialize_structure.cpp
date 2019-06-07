#include <iostream>
using namespace std;

struct Size {
    int width, height;
    /*constructor
    Size () {}
    Size (int width, int height) {
        this->width = width;
        this->height = height;
    }*/
};

struct Point {
    int top, left;
 /*constructor
    Point () {}
    Point (int top, int left) {
        this->top = top;
        this->left = left;
    }*/
};

struct Rectangle {
    Size size;
    Point point;
/*construtor    
    Rectangle (Size size1, Point point) {
        this->size = size1;
        this->point = point;
    }*/
    void pp(){
        cout << this->size.width << ","<<this->size.height<<";"<<this->point.top<<";"<<this->point.left<<endl;;
    }
};

int main(){
/* need constructor
Size size(10, 11);
Point point(5, 6);
Rectangle rect(size, point); */
Size size{10, 11};
Point point{5, 6};
Rectangle rect{size, point};  
rect.pp();

Rectangle rect2 = {{10, 10}, {5, 5}};   
rect2.pp();
}

