#include <iostream>
struct A {
    int x;
    A(int x = 1): x(x) {std::cout << "A user-defined default constructor\n";}
};
struct B: A { // B::B() is implicitly-defined, calls A::A()
};
 
struct C {
    A a; // C::C() is implicitly-defined, calls A::A()
};
 
struct D: A {
    D(int y): A(y) {}
    //D(): A() {}
    // D::D() is not declared because another constructor exists
};
 
struct E: A {
    E(int y): A(y) {}
    E() = default; // explicitly defaulted, calls A::A()
    //E():A(){ std::cout << "in E\n"; }  //my view:same as above
};
 
struct F {
    int& ref; // reference member
    const int c; // const member
    // F::F() is implicitly defined as deleted
};
 
int main() {
    //A a;
    A a;     std::cout << a.x << std::endl;
    A aa(2);  std::cout << aa.x << std::endl;
    B b;      std::cout << b.x << std::endl;
  //B b(3);  //wrong
    C c;  std::cout << c.a.x << std::endl;
  //D d; // compile error
    D dd(4);  std::cout <<dd.x << std::endl;
    E e;  std::cout << e.x << std::endl;
    E ee(5); std::cout << ee.x << std::endl;
  //F f; // compile error
}
