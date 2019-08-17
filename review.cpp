//bilatoral mapping
enum Season { Summer, Fall, Winter, Spring };
string arSeason[] = {"Summer", "Fall", "Winter", "Spring"};  //enum --> String  
map<string, Season> seasons = {                              //String --> enum
    {"Summer", Summer},
    {"Fall", Fall},
    {"Winter", Winter},
    {"Spring", Spring}
};
cout <<Winter << " " << arSeason[Winter] << endl;
cout <<"Winter" << " " << seasons["Winter"] << endl;
cout << (Winter==Season(2)) << endl;


map<int, C> m;
m[7] = C(1);
//m[7] call def constructor
//C(1) call defined constructor
//= call assign constructor

//three ways
class MyClass {
    public:
        MyClass(int a) : var(a){ }
        void printInfo() {
            cout <<         var <<endl;
            cout <<   this->var <<endl;
            cout << (*this).var <<endl;
        }
    private:
        int var;
};


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


set<char> chars { 'A', 'B', 'C', 'D' };   //must be sorted for std::includes
set<char> chars2 { 'A', 'C' };            //must be sorted for std::includes
cout << (chars.find('A') != chars.end()) << endl;  //1
cout << (chars.find('E') != chars.end()) << endl;  //0
bool containAll = includes( chars.begin(), chars.end(), chars2.begin(), chars2.end());   //1

int container[] = {5,10,15,20,25,30,35,40,45,50};
std::sort (container,container+10);   //5 10 15 20 25 30 35 40 45 50


std::vector<int> myvector = {32,71,12,45,26,80,53,33};
int myints[] = {32,71,12,45,26,80,53,33};
std::vector<int> myvector (myints, myints+8);
// using default comparison (operator <):
std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
// using object as comp
std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) std::cout << ' ' << *it;

//Prefix ++ operator overloading with return type    | //postfix ++ operator overloading: int inside barcket(int)
class Check{                                           class Check{
  private:                                               private:
    int i;                                                 int i;
  public:                                                public:
    Check(): i(0) {  }                                     Check(): i(0) {  }
    Check operator ++() {                            |     Check operator ++ (int){
      Check temp;                                            Check temp;
      temp.i = ++i;                                  |       temp.i = i++;
      return temp;                                           return temp;
    }                                                      }
    void Display()  { cout << "i=" << i << endl; }         void Display()  { cout << "i=" << i << endl; }
};                                                     };
int main(){                                            int main(){
  Check obj, obj2;                                       Check obj, obj2;
  obj.Display();                                         obj.Display();   //0 0
  obj2 = ++obj;                                      |   obj2 = obj++;
  obj.Display();                                         obj.Display();   //1 1
  obj2.Display();                                        obj2.Display();  //1 0
  return 0;                                              return 0;
}                                                      }


//Prefix ++ operator overloading with return type    | //Prefix ++ operator overloading without return type
#include <iostream>                                    #include <iostream>
using namespace std;                                   using namespace std;

class Check{                                           class Check{
  private:                                               private:
    int i;                                                 int i;
  public:                                                public:
    Check(): i(0) {  }                                     Check(): i(0) {  }
    Check operator ++() {                            |     void operator ++() {
      Check temp;                                    |       ++i;
      temp.i = ++i;                                  <
      return temp;                                   <
    }                                                      }
    void Display()  { cout << "i=" << i << endl; }         void Display()  { cout << "i=" << i << endl; }
};                                                     };
int main(){                                            int main(){
  Check obj, obj2;                                   |   Check obj;
  obj.Display();                                         obj.Display();  //0 0
  obj2 = ++obj;                                      |   ++obj;
  obj.Display();                                         obj.Display();  //1 1
  obj2.Display();                                    <                   //1
  return 0;                                              return 0;
}                                                      }

#define MIN(a,b) (a<b ? a : b)
cout <<"The Minimum number is " << MIN(x, y) << endl;


enum Season {
    Summer, Fall, Winter, Spring
};
enum Season2: char {
    Summer2, Fall2, Winter2, Spring2
};
Season winter = Winter;
int baseValue = winter;           //2
std::cout <<  Fall << std::endl;  //1
std::cout << Fall2 << std::endl;  //1
