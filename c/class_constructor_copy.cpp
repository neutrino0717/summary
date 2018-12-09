#include <iostream>

template <class T>
void prt(const T & str) {
    std::cout << str << std::endl;
}
struct A {
    int n;
    A(int n = 1) : n(n) { }    //default ctor?
    A(const A& a) : n(a.n) { } // user-defined copy ctor
};
 
struct B : A {
    // implicit default ctor B::B()
    // implicit copy ctor B::B(const B&)
};
 
struct C : B {
     C() : B() { }
 private:
     C(const C&); // non-copyable, C++98 style
};
 
int main() {
    A a;        prt(a.n);
    A a1(7);    prt(a1.n);
    A a2(a1);   prt(a2.n);  // calls the copy ctor
    prt("test B");
    B b;        prt(b.n);
    B b2 = b;   prt(b2.n);
    A a3 = b;   prt(a3.n);// conversion to A& and copy ctor
    volatile A va(10); prt(va.n);
    //A a4 = va; // compile error: binding reference of type ‘const A&’ to ‘volatile A’ discards qualifiers
    prt("test C");
    C c;       prt(c.n);
    C c2 = c; // compile error: ‘C::C(const C&)’ is private within this context
}
