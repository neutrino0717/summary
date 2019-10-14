#include <algorithm>
#include <array>        // std::array
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int  pp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '=')  << s << std::string(pad2, '=') << "\n";
}

int  ppp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '-')  << s << std::string(pad2, '-') << "\n";
}

int  pppp(std::string s) {
    std::cout << "# " << s << "\n";
}

int nl() {
    std::cout << std::endl;
}

namespace first { void func(){ cout << "Inside the first namespace" << endl; } };
namespace second{ void func(){ cout << "Inside the second namespace" << endl;} }

int myglobal;
int& foo(){return myglobal;};

//reference
void prt1(int        i){ std::cout << "value      " << i << std::endl; }
void prt2(int&       i){ std::cout << "lvalue ref " << i << std::endl; }
void prt3(const int& i){ std::cout << "const lvalue ref " << i << std::endl; }
void prt4(int&&      i){ std::cout << "rvalue ref " << i << std::endl; }

//extern
extern "C" int xxx; //is just a declaration 
extern "C" { int yyy; } //is a definition

int main(){
  //bilatoral mapping
  enum Season { Summer, Fall, Winter, Spring };
  string arSeason[] = {"Summer", "Fall", "Winter", "Spring"};  //enum --> String //arSeason[Fall]
  map<string, Season> seasons = {                              //String --> enum //seasons["Fall"]
      {"Summer", Summer},
      {"Fall", Fall},
      {"Winter", Winter},
      {"Spring", Spring}
  };

  cout << Winter  << " " << arSeason[Winter]  << endl;
  cout <<"Winter" << " " << seasons["Winter"] << endl;
  cout << (Winter==Season(2)) << endl;

  //three ways
  class MyClass {
      public:
          MyClass(int a=0) : var(a){ cout << "a="<<a<<endl; }
          void printInfo() {
              cout <<         var <<endl;
              cout <<   this->var <<endl;
              cout << (*this).var <<endl;
          }
      private:
          int var;
  };
  //call constr 3 times
  map<int, MyClass> m;
  m[7] = MyClass(999);
    //m[7] call default constructor
    //C(1) call defined constructor
    //=    call assign constructor

  pp("use reference to avoid new object");
  MyClass a[2];              //call def constr
  for (auto  x : a) { }//call copy constr
  for (auto& x : a) { }//no new object
  exit;


  pp("c type array");
  int arr[5];
  int arr1[]  = {11, 35, 62, 555, 989};
  int arr2[5] = {11, 35, 62, 555, 989};
  int x[2][3] = {{2, 3, 4}, {8, 9, 10}};
  //c type array as function parameters
  auto printArray = [](int arr[], int size) { 
      for(int x=0; x<size; x++) { cout <<arr[x]<< " "; }; nl();
  };
  printArray(arr1, 5);
  //void printArray(int arr[], int size) {   //--> note: nested function not supported in c++
  //   for(int x=0; x<size; x++) { cout <<arr[x]<< endl; }
  //}

  //name space
  using namespace first;
  func();//    // This calls function from first name space.  

  pp("1value and rvalue");
  //lvalue occupy identifiable memory, rvalue not
  int i2 = 0;
  int x2 = i2 + 2; //x: rvalue, i+2: lvalue
  // lvalue = 2  --> OK
  // rvalue = 2   --> wrong

  //lvalue create rvalue normally:
  int x4 = i2 + 2;        //i2: lvalue --> i2+2: rvalue
  //rvalue create lvalue sometimes:
  int v[3]; *(v+2) = 4; //v+2: rvalue --> *(v+2): lvalue

  //function or operator yields rvalue normally
  int y = [](int x, int y){return x+y; }(33,44);
  cout << y << endl;

  //function or operator yields lvalue too
  foo() = 50; //foo() yields lvalue
  cout << myglobal << endl;

  //operator [] always yields lvalue
  arr1[1] = 50;

  pp("1value and rvalue reference");
  int& r2 = i2;       //r2 is lvalue reference.
  r2      = 99;       //OK
  //int& r3 = 3;     //error, lvalue reference can only refer to lvalue
  const int& r3 = 2; //OK, this is a exception, constant lvalue can be assigned a rvalue

  int i=40;
  //in square1(      int& x){return x*x;}; square1(i); square1(40);  //OK; error
  //in square2(const int& x){return x*x;}; square2(i); square2(40);  //OK; OK
  auto square1=[](      int& x){cout << x*x; nl();}; square1(i); //square1(40);  //OK; error
  auto square2=[](const int& x){cout << x*x; nl();}; square2(i);   square2(40);  //OK; OK

  int   a5 = 2;  //a is lvalue
  int&  b5 = a5; //b is lvalue ref
  int&& c5 = 7;  //c is rvalue ref
  prt1(1);
  //prt2(1);  //cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  prt3(1);
  prt4(1);
  prt1(a5);
  prt2(a5);
  prt3(a5);
  //prt4(a5);    // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
  prt1(b5);
  prt2(b5);
  prt3(b5);
  //prt4(b5);   // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
  prt1(c5);
  prt2(c5);
  prt3(c5);
  //prt4(c5);  //cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

  pp("int *ptr = NULL;");
  int *ptr = NULL;
  cout << "The value of ptr is " << ptr << endl;  //0

  pp("std::map.find");
  map<int, string>  dic = { {1, "one"}, {2, "two"} };
  bool exists1 = dic.find(1) != dic.end();// 1
  cout << exists1 << endl;

  pp("std::set.find, std::includes");
  set<char> chars { 'A', 'B', 'C', 'D' };   //must be sorted before std::includes
  set<char> chars2 { 'A', 'C' };            //must be sorted before std::includes
  cout << (chars.find('A') != chars.end()) << endl;  //1
  cout << (chars.find('E') != chars.end()) << endl;  //0
  bool containAll = std::includes( chars.begin(), chars.end(), chars2.begin(), chars2.end());   //1
  cout << containAll << endl;

  //unordered_map::find
  std::unordered_map<std::string,double> mymap = {
    {"mom",5.4},
    {"dad",6.1},
    {"bro",5.9},
    {"bro",5.8} };
  std::unordered_map<std::string,double>::const_iterator got = mymap.find ("dad");
  if ( got != mymap.end() ) std::cout << "found" << endl; //found
  std::cout << got->first << " is " << got->second << endl; //dad is 6.1
  cout << mymap.count("bro") << endl;   //1   //1 if an element with a key equivalent to k is found, or zero otherwise.
  cout << mymap.count("abc") << endl;   //0
  cout << mymap.size() << endl;        //3
  std::unordered_map<std::string,std::string>
    first = {{"11","G. Lucas"},{"12","R. Scott"},{"13","J. Cameron"}},
    second  = {{"21","C. Nolan"},{"22","R. Kelly"}};
  first.swap(second);
  for (auto& x: first)  std::cout << x.first << " (" << x.second << "), "; nl();//{{"21","C. Nolan"},{"22","R. Kelly"}};
  for (auto& x: second) std::cout << x.first << " (" << x.second << "), "; nl();//{{"11","G. Lucas"},{"12","R. Scott"},{"13","J. Cameron"}},


}