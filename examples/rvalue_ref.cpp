#include <iostream>
//void prt(int   i){ std::cout << "value " << i << std::endl; }
void prt(int&  i){ std::cout << "lvalue ref " << i << std::endl; }
void prt(int&& i){ std::cout << "rvalue ref " << i << std::endl; }
int main() {
    int a = 5;  //a is lvalue
    int& b = a; //b is lvalue ref
    int&& c = 4 ;    //c is rvalue ref  
    prt(3);   //prt(int i) or prt(int&& i)
    prt(a);   //prt(int i) or prt(int&  i)
    prt(b);     //prt(int i) or prt(int&  i)
    prt(c);
}

