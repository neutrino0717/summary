map<int, C> m;
m[7] = C(1);
//m[7] call def constructor
//C(1) call defined constructor
//= call assign constructor


A a[2];              //call def constr
for (auto  x : a) { }//call copy constr
for (auto& x : a) { }//no new object

int aaa[5];
int arr[] = {11, 35, 62, 555, 989};
int arr[5] = {11, 35, 62, 555, 989};
int x[2][3] = {{2, 3, 4}, {8, 9, 10}};

namespace first { void func(){ cout << "Inside the first namespace" << endl; } }
namespace second{ void func(){ cout << "Inside the second namespace" << endl;} }
using namespace first;
int main () { func(); return 0; } //    // This calls function from first name space.


void prt(int   i){ std::cout << "value " << i << std::endl; }
void prt(int&  i){ std::cout << "lvalue ref " << i << std::endl; }
void prt(int&& i){ std::cout << "rvalue ref " << i << std::endl; }
int main() {
    int a = 5;  //a is lvalue
    int& b = a; //b is lvalue ref
    int&& c ;   //c is rvalue ref
    prt(3);      //prt(int i) or prt(int&& i)
    prt(a);      //prt(int i) or prt(int&  i)
    prt(b);      //prt(int i) or prt(int&  i)
}

int *ptr = NULL;
cout << "The value of ptr is " << ptr ;  //0

extern "C" int x; //is just a declaration extern "C" { int y; } //is a definition

/*
 * unique smart pointer
 */
//bad way
Dog* dg = new Dog("KeJi");
delete dg;

//use unique pointer
{
unique_ptr<Dog> dg2(new Dog("ErHa"));
}

//return the raw point, and dg3 release the ownereship. dog will not be deleted
unique_ptr<Dog> dg3(new Dog());
Dog* p = dg3.release();
if(!dg3){cout << "dg3 is empty\n";} //dg->bark();

//reset to another dog
{
unique_ptr<Dog> dg4(new Dog("LaPuLaDuo"));
dg4.reset(new Dog("JinMao"));//dog is destroyed: LaPuLaDuo
if(!dg4){cout << "dg4 is empty\n";}else{cout << "dg4 is not empty\n";}  //dg4 is not empty
}                                                                       //dog is destroyed: JinMao


//reset without any parameters\n";
{
unique_ptr<Dog> dg5(new Dog("Fadou"));
//dg5 = nullptr; //or
dg5.reset(); //dog is destroyed: Fadou
if(!dg5){cout << "dg5 is empty\n";}else{cout << "dg5 is not empty\n";}  //dg5 is empty
}

//transfer ownership to another unique ptr with move
{
unique_ptr<Dog> dg6(new Dog("SaMoYe"));
unique_ptr<Dog> dg7(new Dog("ZangAo"));
dg7 = move(dg6);//1. ZangAo destoryed
                //2. dg6 becomes empty
                //3. dg7 owns SaMoYe 
}

void f(unique_ptr<Dog> p){ p->bark(); }
cout << "\n:function parametor\n";
unique_ptr<Dog> dg8(new Dog("Tianyuan"));
f(move(dg8)); //Dog Tianyuan rules!
              //dog is destroyed: Tianyuan
              

//basically the two are the same, however if explicit is used in constr, the  2nd is not ok
C c1(7)       //direct-initialization
C c2 = 7     // called copy-initialization

