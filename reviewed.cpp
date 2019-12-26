#include <algorithm>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <thread>
#include <assert.h>

using namespace std;
int  pp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '=')  << s << std::string(pad2, '=') << "\n";
    return 0;
}

void  ppp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '-')  << s << std::string(pad2, '-') << "\n";
}

void  pppp(std::string s) {
    std::cout << "# " << s << "\n";
}

void nl() {
    std::cout << std::endl;
}

template <class T, class U>
void pmap(const std::map<T, U>& m){
  for (const auto& i: m)  cout << i.first << " -> " << i.second << endl;
  //for (const auto& i: m)  cout << typeid(i).name() << endl;
}

template<class T>
void pvector(const std::vector<T>& v){
  for(const auto& i: v) cout << i << " "; nl();
}

struct Size {
    int width, height;
    /**/
    Size () {}
    Size (int width, int height) {
      this->width = width;
      this->height = height;
    }/**/
};

struct Point {
    int top, left;
    Point () {}
    Point (int top, int left) {
      this->top = top;
      this->left = left;
    }
};

struct Rectangle {
    Size size;
    Point point;
    /**/
    Rectangle (Size size1, Point point) {
      this->size = size1;
      this->point = point;
    }/**/
    void pp(){
        cout << this->size.width << ","<<this->size.height<<";"<<this->point.top<<","<<this->point.left<<endl;;
    }
};



namespace first { void func(){ std::cout << "Inside the first namespace" << endl; } };
namespace second{ void func(){ std::cout << "Inside the second namespace" << endl;} }

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
  pp("bilatoral mapping");
  enum Season { Summer, Fall, Winter, Spring };       
  string arSeason[] = {"Summer", "Fall", "Winter", "Spring"};  //enum --> String //arSeason[Fall]
  map<string, Season> seasons = {                              //String --> enum //seasons["Fall"]
      {"Summer", Summer},
      {"Fall", Fall},
      {"Winter", Winter},
      {"Spring", Spring}
  };

  std::cout << Winter  << " " << arSeason[Winter]  << endl;
  std::cout <<"Winter" << " " << seasons["Winter"] << endl;
  std::cout << (Winter==Season(2)) << endl;
  pp("enum");     
  enum Season1       { Summer1, Fall1, Winter1, Spring1 };  //c++ 03: enum are basically integers
  enum Season2: char { Summer2, Fall2, Winter2, Spring2 };
  enum Season3: int  { Summer3, Fall3, Winter3, Spring3 };
  std::cout << Fall1 << std::endl;  //1
  std::cout << Fall2 << std::endl;  //1
  std::cout << Fall3 << std::endl;  //1
  Season w1 = Winter;
  int    w2 = w1;           //2

  enum class apple {green, red};                          //c++ 11: introduct enum class, more strong typed
  enum class orange {big, small};                         //c++ 11: introduct enum class, more safe to use
  apple ap = apple::red;                 //not 1
  orange og = orange::small;             //not 1
  //std::cout << ap == og << std::endl;    //compile fails because we haven't define "== (apple, orange)"

  //exit(1);
  //three ways
  class MyClass {
      public:
          MyClass(int a=0) : var(a){ std::cout << "a="<<a<<endl; printInfo(); }
          void printInfo() {
              std::cout <<         var <<endl;
              std::cout <<   this->var <<endl;
              std::cout << (*this).var <<endl;
          }
      private:
          int var;
  };
  //call constr 3 times
  map<int, MyClass> m;
  m[7] = MyClass(999);
    //m[7] call default constructor
    //MyClass(999) call defined constructor
    //=    call assign constructor
  //exit(1);

  pp("use reference to avoid new object");
  MyClass a[2];              //call def constr
  cout << "def constr called for two elements" << endl;
  for (auto  x : a) { cout << " copy constr called " << endl; }//call copy constr, readonly access.
  for (auto& x : a) { cout << " no new object " << endl; }//no new object,    changes the values in a by x
  //exit(1);

  pp("c type array");
  int arr[5];
  int arr1[]  = {11, 35, 62, 555, 989};
  int arr2[5] = {11, 35, 62, 555, 989};
  int x[2][3] = {{2, 3, 4}, {8, 9, 10}};
  //c type array as function parameters
  auto printArray = [](int arr[], int size) { 
      for(int x=0; x<size; x++) { std::cout <<arr[x]<< " "; }; nl();
  };
  printArray(arr1, 5);
  //void printArray(int arr[], int size) {   //--> note: nested function not supported in c++
  //   for(int x=0; x<size; x++) { cout <<arr[x]<< endl; }
  //}
  //exit(1);
  
  //name space
  using namespace first;
  func();//    // This calls function from first name space.  

  pp("1value and rvalue");
  {
    //lvalue occupy identifiable memory, rvalue not
    int i2 = 0;
    int x2 = i2 + 2; //x2: lvalue, i2+2: rvalue
    // lvalue = 2  --> OK
    // rvalue = 2   --> wrong

    //lvalue create rvalue normally:
    int x4 = i2 + 2;        //i2: lvalue --> i2+2: rvalue
    //rvalue create lvalue sometimes:
    int v[3]; *(v+2) = 4;   //v+2: rvalue --> *(v+2): lvalue

    //function or operator yields rvalue normally
    int y = [](int x, int y){return x+y; }(33,44);
    std::cout << y << endl;

    //function or operator yields lvalue too
    foo() = 50; //foo() yields lvalue   
    cout << myglobal << endl;

    auto foo9 = [&]()->int&{return myglobal; };
    foo9() = 60;
    cout << myglobal << endl;

    //operator [] always yields lvalue
    arr1[1] = 50;
    //exit(1);

  }

  pp("1value and rvalue reference");
  {
    int i2;
    int& r2 = i2;       //r2 is lvalue reference.
    r2      = 99;       //OK
    //int& r3 = 3;     //error, lvalue reference can only refer to lvalue
    const int& r3 = 2; //OK, this is a exception, constant lvalue can be assigned a rvalue

    int i=40;
    //in square1(      int& x){return x*x;}; square1(i); square1(40);  //OK; error
    //in square2(const int& x){return x*x;}; square2(i); square2(40);  //OK; OK
    auto square1=[](      int& x){cout << x*x; nl();}; square1(i); //square1(40);  //OK; error
    auto square2=[](const int& x){cout << x*x; nl();}; square2(i);   square2(40);  //OK; OK

    //reference
    //void prt1(int        i){ std::cout << "value      " << i << std::endl; }
    //void prt2(int&       i){ std::cout << "lvalue ref " << i << std::endl; }
    //void prt3(const int& i){ std::cout << "const lvalue ref " << i << std::endl; }
    //void prt4(int&&      i){ std::cout << "rvalue ref " << i << std::endl; }
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
    //prt4(b5);    // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    prt1(c5);
    prt2(c5);
    prt3(c5);
    //prt4(c5);    // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    //exit(1);
  }

  pp("nullptr replace NULL in C++ 03");
  {
    int *ptr1 = NULL;
    cout << "The value of ptr1 is " << ptr1 << endl;  //NULL is 0 which cause issues
    int *ptr2 = nullptr;
    cout << "The value of ptr2 is " << ptr2 << endl;

  }

  pp("std::map.find()");
  {
    map<int, string>  dic = { {1, "one"}, {2, "two"} };
    bool exists1 = dic.find(2) != dic.end();// 1
    cout << exists1 << endl;
    //exit(1);    
  }

  pp("std::set.find(), std::includes()");
  {
    set<char> chars { 'A', 'B', 'C', 'D' };   //must be sorted before std::includes
    set<char> chars2 { 'A', 'C' };            //must be sorted before std::includes
    cout << (chars.find('A') != chars.end()) << endl;  //1
    cout << (chars.find('E') != chars.end()) << endl;  //0
    bool containAll = std::includes( chars.begin(), chars.end(), chars2.begin(), chars2.end());   //1
    cout << containAll << endl;
    //exit(1);
  }

  pp("unordered_map::find");
  {{
    std::unordered_map<std::string,double> mymap = {
      {"mom",5.4},
      {"dad",6.1},
      {"bro",5.9},
      {"bro",5.8} 
    };
    std::unordered_map<std::string,double>::const_iterator got = mymap.find ("dad");
    if ( got != mymap.end() ) std::cout << "found" << endl; //found

      std::cout << got->first << " is " << got->second << endl; //dad is 6.1
      cout << mymap.count("bro") << endl;   //1   //1 if an element with a key equivalent to k is found, or zero otherwise.
      cout << mymap.count("abc") << endl;   //0
      cout << mymap.size() << endl;         //3
      std::unordered_map<std::string,std::string>
        first1 = {{"11","G. Lucas"},{"12","R. Scott"},{"13","J. Cameron"}},
        second1  = {{"21","C. Nolan"},{"22","R. Kelly"}};
      first1.swap(second1);
      for (auto& x: first1)  std::cout << x.first << " (" << x.second << "), "; nl();//{{"21","C. Nolan"},{"22","R. Kelly"}};
      for (auto& x: second1) std::cout << x.first << " (" << x.second << "), "; nl();//{{"11","G. Lucas"},{"12","R. Scott"},{"13","J. Cameron"}},
    //exit(1);
  }}


  pp("std::string::substr()");
  {
    string str = "one way ticket";
    cout << str.substr(4, 3) << endl;     //return "way"`,  str unchanged
    //exit(1);
  }

  pp("std::string::{erase,find}");
  {
    string str = "This is an example"; str.erase(0, 5);
    cout << str << endl;  //erase 0~5, return "is an example",
    str = "This is an example"; str.erase(4);
    cout << str << endl;  //erase 4~$ , return "This",
    str = "This is an example"; str.erase(str.find(' ')); //s.find(' ') return 4
    cout << str << endl;                                  //erase 4~$ , return "This"
    str = "This is an example"; str.erase(std::find(str.begin(), str.end(), ' ')); //std::find() return InputIt 
    cout << str << endl;  //erase 4~5, return "Thisis an example" 
    //exit(1);
  }

  pp("std::string::{erase,remove}");
  {
    //remove all spaces https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
    auto is_space = [](unsigned char x){return isspace(x);};
    string str = "This is an example";
    string str2 = str;
    if (str == str2) cout << "equal" << endl;
    str.erase(remove(str.begin(),   str.end(), ' '),      str.end());
    cout << str << endl;
    cout << str2 << endl;

    str = "This is an example";
    str.erase(remove_if(str.begin(), str.end(), is_space), str.end());
    cout << str << endl;
    cout << str.length() <<endl;
    //1 remove_if() change the string str to     "Thisisanexample   "
    //2 remove_if() return iterator pointing to  "Thisisanexample   "   //? rreally?
    //                                                           ^
    str = "This is an example";
    remove_if(str.begin(), str.end(), is_space);
    cout << str.length() <<endl;
    //cout << "-->" << str << "<--"<< endl;
    //string str2=" aaa, bbb, ccc   ";
    //cout << "-->" << str2 << "<--"<< endl;
    //exit(1);
  }

  pp("set: auto sort");
  {
    unordered_set<int> charu{'B', 'A', 'C', 'D'};
    set<int>           charv{'B', 'A', 'C', 'D'};
    for (int c:charu) cout << c << ":"; nl();           //68:67:65:66:
    for (int c:charv) cout << c << ","; nl();           //65,66,67,68,
    for (int c:charv) cout << string(1,c) << ";"; nl(); //A;B;C;D;
    //exit(1);
 }

  pp("all_of, any_of");
  {
    std::array<int,8> foo2 = {3,5,7,11,13,17,19,23};
    cout << std::all_of (foo2.begin(), foo2.end(), [](int i){return i%2;}) << endl;  //1, all are odd
    cout << std::none_of(foo2.begin(), foo2.end(), [](int i){return i%2 == 0;}) << endl;  //1, all are odd
    std::array<int,7> foo3 = {0,1,-1,3,-3,5,-5};
    cout << std::any_of(foo3.begin(), foo3.end(), [](int i){return i<0;}) << endl;//1, some are negative
    //exit(1);
  }

  pp("pair");
  {
    pair<string, int> p1 = make_pair("moon", 17);
    pair<string, int> p2 =          {"moon", 17};
    pair<string, int> p3            {"moon", 17};
    cout << p1.first << " "  << p1.second << "\n";
    cout << p2.first << " "  << p2.second << "\n";
    cout << p3.first << " "  << p3.second << "\n";
    //exit(1);
  }
  pp("tuple is for one-time usage");
  {
    //tuple for one-time usage, struct for readability
    struct Person{ string name; int age; } p = {"moon", 11};
    cout << p.name    << " " << p.age     << endl;
    tuple<string, int> t = {"moon", 7};
    cout << get<0>(t) << " " << get<1>(t) << endl;
    //exit(1);
  }

  pp("tuple get<>() returns reference");
  {
    tuple<string, int, char> t1("moon", 99, 'a');
    cout << get<0>(t1) << " " <<  get<1>(t1) << " " << get<2>(t1) << endl;   //23 hel`1lo a
    get<0>(t1) = "bye"; //get<>() returns reference
    cout << get<0>(t1) << " " <<  get<1>(t1) << " " << get<2>(t1) << endl;   //23 bye a
    string& s = get<0>(t1);
    s = "changed";       //s is reference
    cout << get<0>(t1) << " " <<  get<1>(t1) << " " << get<2>(t1) << endl;   //23 changed a

    tuple<string, int, char> t2; //default constructor
    tuple<string, int, char> t3 = {"moon", 3, 'a'};  //or
    auto                     t4 = tuple<string, int, char>("moon", 4, 'a');
    auto                     t5 = make_tuple("moon", 5, 'a'); //the same, make things easier
    cout << get<0>(t2) << "_" <<  get<1>(t2) << "_" << get<2>(t2) << endl;
    cout << get<0>(t3) << " " <<  get<1>(t3) << " " << get<2>(t3) << endl;
    cout << get<0>(t4) << " " <<  get<1>(t4) << " " << get<2>(t4) << endl;
    cout << get<0>(t5) << " " <<  get<1>(t5) << " " << get<2>(t5) << endl;
    //exit(1);
  }

  pp("tuple can store references");
  //None of the stl container can store reference, they always use copy/move
  //string st = "to be changed";
  //tuple<string&> t6(st); //store reference
  //get<0>(t6) = "changed3";
  //cout << st << endl;  //changed3
  //tuple<string&> t4 = make_tuple(ref(st));
  //get<0>(t4) = "changed4";
  //cout << st << endl;  //changed4

  pp("tuple can store references 2");
  {
    auto t2 = tuple<int, string, char>(27, "hello", 'b');

    int ax; string ay; char az;
    //make_tuple(ax, ay, az) = t2;
    make_tuple(ref(ax), ref(ay), ref(az)) = t2;
    cout << ax << " " << ay << " " << az << endl;  //27 hello b

    int bx; string by; char bz;
    std::tie(bx, std::ignore, bz) = t2;           //same as above, ignore y
    cout << bx << " " << by << " " << bz << endl;  //27  b
    std::tie(bx, by, bz) = t2;                    //
    cout << bx << " " << by << " " << bz << endl;  //27 hello b
    //exit(1);
  }

  pp("tuple catenate");
  {
    tuple<string, int, char> t2; //default constructor
    tuple<string, int, char> t3 = {"moon", 3, 'a'};  //or
    auto t8 = tuple_cat(t2, t3);  //suport cat
    cout << tuple_size<decltype(t8)>::value << endl; //type traits, 6
    //exit(1);
  }

  pp("tuple swap");
  {
    int sa=1, sb=2, sc=3;
    tie(sb, sc, sa) = make_tuple(sa, sb, sc);
    cout << sa << sb << sc << endl;
    //exit(1);
  }

  pp("multi index map");
  {
    map<tuple<int, char, float>, string> mt;
    mt[make_tuple(2,'a',2.3)] = "test it";
    cout <<  mt[make_tuple(2,'a',2.3)] << endl;
    //exit(1);    
  }

  pp("std::transform");
  {
    string str = "Lower and upper";
    std::transform(str.begin(), str.end(), str.begin(), ::tolower); //::tolower global namespace, which is tolower of C lauguage. str is "lower and upper"
    cout << str << endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); //str is "LOWER AND UPPER"
    cout << str << endl;
    //exit(1);
  }

  pp("std::set::{insert,erase,clear}");
  {
    set<char> set1{ 'A', 'B', 'C' };
    set1.insert('D'); //{ 'A', 'B', 'C', 'D' }
    set1.erase('A');  //{ 'B', 'C', 'D' }
    for(const char &c: set1) cout << c << ";"; nl();//B;C;D;
    set1.clear();     //{ }
    for(const char &c: set1) cout << c << ";"; nl();
    //exit(1);
  }

  pp("std::{set_union,intersection,set_difference,equal}");
  {
    set<int> sss1{ 1, 2, 3, 4 };
    set<int> sss2{ 3, 4, 5 };
    set<int> sss3, sss4, sss5;
    vector <int> vthird;
    insert_iterator<set<int>> iterator3(sss3, sss3.begin());
    insert_iterator<set<int>> iterator4(sss4, sss4.begin());
    insert_iterator<set<int>> iterator5(sss5, sss5.begin());    
  
    set_union       (sss1.begin(), sss1.end(), sss2.begin(), sss2.end(), iterator3 );  //sss3 is { 1, 2, 3, 4, 5 }
    set_intersection(sss1.begin(), sss1.end(), sss2.begin(), sss2.end(), iterator4);   //sss4 is { 3, 4 }
    set_difference  (sss1.begin(), sss1.end(), sss2.begin(), sss2.end(), iterator5);   //sss5 is { 1, 2 }
    set_intersection(sss1.begin(), sss1.end(), sss2.begin(), sss2.end(), back_inserter(vthird)); //third is { 3, 4 }
    for (const int& i: sss3) cout << i; nl();
    for (const int& i: sss4) cout << i; nl();
    for (const int& i: sss5) cout << i; nl();
    for (const int& i: vthird) cout << i; nl();
    cout << equal   (sss1.begin(), sss1.end(), sss2.begin(), sss2.end()) << endl;
    //exit(1);
  }

  pp("std::map::{erase, find, end}");
  {
    std::map<std::string,std::string> mymap2;
    // populating container:
    mymap2["U.S."] = "Washington";
    mymap2["U.K."] = "London";
    mymap2["France"] = "Paris";
    mymap2["Russia"] = "Moscow";
    mymap2["China"] = "Beijing";
    mymap2["Germany"] = "Berlin";
    mymap2["Japan"] = "Tokyo";

    cout << "\n=>sorted:\n";         pmap(mymap2);        
    mymap2.erase ( mymap2.begin() );      // erasing by iterator, china removed
    cout << "\n=>China removed:\n";  pmap(mymap2);
    mymap2.erase ("Germany");             // erasing by key, germany removed
    cout << "\n=>Germany removed:\n";pmap(mymap2);
    mymap2.erase ( mymap2.find("U.K."), mymap2.end() ); // erasing by range, all removed
    cout << "\n=>U.K. U.S. removed:\n"; pmap(mymap2);
    //exit(1);
  }

  pp("Initializer list for struct");
  {
    //way1. need constructor
    Size size(10, 11);
    Point point(5, 6);
    Rectangle rect(size, point);
    rect.pp();//10,11,5,6
    //exit(1);
  }

  {
    //way2, Initializer_list, no need for constructor
    Size size{1, 2};
    Point point{3, 4};
    Rectangle rect{size, point};  
    rect.pp();//1,2,3,4
    //exit(1);
  }

  {
    //way3, Initializer_list
    Rectangle rect2 = {{5, 6}, {7, 8}};   
    rect2.pp();//5,6,7,8
    //exit(1);
  }

  pp("Initializer list for Array of integer/string");
  {
    int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    string gameList[] { "soccer", "hockey", "basketball" }; //the same as above
    //exit(1);
  }

  pp("use constructor for Array of objects");
  {
    Point point2[] { Point(1, 2), Point(3, 4) };
    Point point3[] { Point{1, 2}, Point{3, 4} };
    //exit(1);
  }

  pp("Initializer list for map");
  {
    map<int, Point> point4 { {1, Point{11, 12}}, {2, Point{21, 22}} };
    //exit(1);
  }

  pp("iostream");
  {
    std::cout.put('P'); nl();         //low-level I/O
    //exit(1);
  }

  pp("time -> time_t --localtime/gmtime----> tm -> string");
  {
    time_t now = time(0);//time(0) will return the current second count: 1566743108
    tm tm0 = *localtime(&now);
    tm tm1={2, 30, 22, 17, 7-1, 1975-1900}; //or
    //tm* gmtm = gmtime(&now); // convert now to tm struct for UTC
    int year = tm1.tm_year + 1900;
    int month = tm1.tm_mon + 1;
    int day = tm1.tm_mday;
    int hour = tm1.tm_hour;
    int minute = tm1.tm_min;
    int second = tm1.tm_sec;
    int dayOfWeek = tm1.tm_wday;
    cout << year << ":" << month  << ":" << day << ":" << hour << ":" << minute << ":" << second << endl; //1975:7:17:22:30:2
    //2019:8:25:22:21:26
    //exit(1);
}

  pp("time -> time_t --ctime--------> string");
  {
    time_t now2 = time(0);  //1566743108
    cout << now2 << endl;
    char* dt = ctime(&now2); // convert now to string form
    cout << "The local date and time is: " << dt << endl;//Sun Aug 25 22:25:08 2019
    //exit(1);
  }

  pp("time -> time_t --gmtime-->tm --asctime---> string");
  {
    time_t now2 = time(0);  //1566743108
    tm *gmtm2 = gmtime(&now2); // convert now to tm struct for UTC
    char* dt = asctime(gmtm2);
    cout << "The UTC date and time is:"<< dt << endl; //Sun Aug 25 14:25:08 2019
    //exit(1);
  }

  pp("srand");
  {
    srand(time(0)); //time(0) will return the current second count
    for (int x = 1; x <= 7; x++) cout << 1 + (rand() % 6) << " ";  //4 5 3 6 5 1 2
    //exit(1);
  }

  //#include <sstream>
  // istringstream is for input, 
  // ostringstream for output. 
  //  stringstream is input and output. You can use stringstream pretty much everywhere.
  pp("ostringstream and istringstream and sstream");
  {
    bool boolValue;
    int intValue;
    std::istringstream("true") >> std::boolalpha >> boolValue;   //or use stringstream
    std::cout << boolValue << std::endl;   //1
    std::istringstream("10") >> std::hex >> intValue;
    std::cout << intValue << std::endl;    //1
    
    ostringstream ss;   //or use stringstream
    ss << "hex of 89 is: " << hex << 89 << "\noct of 89 is: " << oct << 89;
    cout << ss.str() << endl; //hex of 89 is: 59. oct of 89 is: 131

    stringstream ss2("1 2 3 4 5");
    int numbers[5];
    /*template<class InputIterator, class OutputIterator>
      OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result) {
        while (first!=last) { *result = *first; ++result; ++first; }
        return result;
      }*/
    // input one int + one char --> "1" + " " from ss2
    copy(istream_iterator<int, char>(ss2), istream_iterator<int, char>(), numbers); //numbers in {1, 2, 3, 4, 5}
    for(int &i: numbers) cout << i << ":"; cout << endl;
    //exit(1);
  }

  /*
  #include <fstream>
  fstream library contains three classes:
    ofstream: Output file stream that creates and writes information to files.
    ifstream: Input file stream that reads information from files.
     fstream: General file stream, with both ofstream and ifstream capabilities that allow it to create, read, and write information to files.
  */
  pp("ofstream and ifstream");
  {
    //ofstream outfile;
    //outfile.open("file.dat", ios::out | ios::trunc );
    ofstream MyFile1("/tmp/test.txt");
    MyFile1 << "This is awesome! \n";
    MyFile1.close();

    ifstream MyFile("/tmp/test.txt");
    string line; 
    while ( getline (MyFile, line) ) cout << line << '\n';   //This is awesome!
    MyFile.close();
    //exit(1);
  }

  pp("ofstream and ifstream -> binary");   
  {
    std::ofstream ostrm("/tmp/Test.bin", std::ios::binary);
    double d = 3.14;
    ostrm.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
    ostrm << 123 << '\n';                      // text output

    std::ifstream istrm("/tmp/Test.bin", std::ios::binary);  // read back
    istrm.read(reinterpret_cast<char*>(&d), sizeof d);
    std::cout << "read back: " << d  << '\n'; //read back: 3.14
    //exit(1);
  }

  pp("std::thread");   
  {
    static bool s_finished = false;
    auto DoWork =[]() {
      while(!s_finished){
        std::cout << "in thread id=" << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(0.2s);
      }
    };

    std::thread worker(DoWork);

    std::this_thread::sleep_for(0.5s);
    s_finished = true;
    worker.join();
    std::cout << "Main thread id=" << std::this_thread::get_id() << std::endl;
    std::cout << "finished! \n";
    //exit(1);
  }


  pp("regex_match(string, smatch, regex)");
  {
    string data1 = "aaab";
    string data2 = "aaaba";
    regex reg("a+b");
    smatch match;
    cout << regex_match(data1, match, reg) << endl;  //1, match the whole string
    cout << regex_match(data2, match, reg) << endl;  //0.

    pp("regex_replace(string, regex, string)");
    string data = "Pi = 3.14, exponent = 2.718, done.";
    regex reg2(R"(\d+\.\d+)", regex::icase);
    cout << regex_replace(data, reg2, "<f>$0</f>") << endl; //Pi = <f>3.14</f>, exponent = <f>2.718</f>, done.
    //exit(1);
  }

  pp("typeid");
  {
    auto x = 4;
    auto y = 3.37;
    auto ptrx = &x;
    auto ptry = &y;  
    cout << typeid(x).name() << endl        //i  int
         << typeid(y).name() << endl        //d  double
         << typeid(ptrx).name() << endl     //Pi point_to_int
         << typeid(ptry).name() << endl;    //Pi point_to_int
    //exit(1);
  }

  pp("decltype");
  {
	  //decltype
	  decltype(pp("hello")) x;//Data type of x is same as return type of pp(), which return 0
  	cout << typeid(x).name() << endl;   //i   int
    cout << typeid(decltype(pp("hello"))).name() << endl;
    exit(1);
  }

  pp("std::sort vector");
  {
    struct myclass { //how to understand: think struct as class
      bool operator() (int i,int j) { return (i<j);}
    } myobject;

    //1. using default comparison (operator <):
    std::vector<int> myvector = {32,71,12,45,26,80,53,33};
    std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it) cout << *it << " "; nl();

   //2. using function
    std::sort (myvector.begin()+4, myvector.end(), [](int x, int y){ return x<y;}); // 12 32 45 71(26 33 53 80)
    for(auto i: myvector) cout << i << " "; nl();

    //3. using object as comp
    std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
    for(auto i: myvector) cout << i << " "; nl();
    exit(1);
  }

  pp("std:sort array");
  {
    int container[] = {5,10,15,20,25,30,35,40,45,50};
    std::sort (container,container+10);   //5 10 15 20 25 30 35 40 45 50
    for(auto i: container) cout << i << " "; nl();
    exit(1);
  }

  pp("const, const_cast, static_cast");
  {
    //if const is on the left of *, data is const
    int i = 7;
    int const *p1 = &i;
    const int *p2 = &i;
    //if const is on the right of *, pointer is const
    int* const p3 = &i;

    //cast is bad, avoid them as much as possible
    const int i2 = 9; 
    //i2 = 6; //compile error
    const_cast<int&>(i2) = 6;  //const_cast cast away the constness of i 
    int j;
    //static_cast<const int&>(j) = 7; //cast data into a const, then assign a valued which throws error
    exit(1);
  }

  pp("static and run-time assert");
  {
    //include "assert.h"
    int i = 10;
    int* ptr = &i;
    static_assert(sizeof(int) == 4, "The code will not work if size of integer is not 4"); 
    assert(ptr != nullptr);          //abort exection if ptr==nullptr
    exit(1);
  }

  pp("delecating constructor in c++ 11");
  {
    class dog{
      int age = 9;//c++ 11 allow in-class class member initialization. so all constructors initialized age here.
      dog(){ /*do something*/}
      dog(int a): dog() { /*do something else*/}
    };//limitation: dog() can only be invoked at the beginning of dog(int a) 

  }

  pp("std::swap");
  {
    int a = 5, b = 3;
    std::cout << a << ' ' << b << '\n';
    std::swap(a,b);
    std::cout << a << ' ' << b << '\n';
  }

  pp("std::partial_sum");
  {
    //std::vector<int> v = {2, 2, 2, 2, 2, 2, 2};
    std::vector<int> v(7, 2);
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " ")); nl();
    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    pvector(v);
  }

  pp("std::to_string()");
  {
    double f;
    f = 12.34; std::cout << f << " " << std::to_string(f) << endl;
    f = 1e-2;  std::cout << f << " " << std::to_string(f) << endl;
    f = 3e-5;  std::cout << f << " " << std::to_string(f) << endl;
    f = 12345; std::cout << f << " " << std::to_string(f) << endl;
    f = 12345678; std::cout << f << " " << std::to_string(f) << endl;
  }

  pp("std::advance()");
  {
    //std::list<int> mylist;
    std::vector<int> mylist; //or
    for (int i=0; i<10; i++) mylist.push_back (i*10);
    auto it = mylist.begin();
    std::advance (it, 5);  cout << *it << endl; //50, Advances the iterator it by 5 element positions
    auto it2 = std::prev(it, 2); cout << *it2 << endl;//30
    auto it3 = std::next(it, 2); cout << *it3 << endl;//70
    pp("std::for_each()");
    std::for_each(mylist.begin(), std::next(mylist.begin(), 3), [](int i){cout << i << " "; }); nl(); //0 10 20
    cout << std::distance(it2, it3) << endl;          //4
  }

  //todo static_cast



}

//lib: -pthread