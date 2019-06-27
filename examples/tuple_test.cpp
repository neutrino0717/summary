#include <tuple>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
int main(){
    std::pair<int, string> p = make_pair(23, "hello");
    cout << p.first << " " << p.second << endl;

    //tuple is extended pair
    tuple<int, string, char> t(32, "penny wise", 'a');
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    get<1>(t) = "pound foolish";

    //note: get function return reference, test below
    string& s = get<1>(t);
    s = "fresh pond";
    cout << s << endl;

    //int j = 1;
    //get<j>(t); //j must be compile time constant

    //v[] also return refence, test below
    vector<int> v(3); //size 3
    v[0]=3;
    v[1]=4;
    v[2]=5;
    int& i = v[2];
    i = 7;
    for (int i:v) cout << i << " "; cout << endl;

    tuple<int, string, char> t2; //default constructor
    cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;
    t2 = tuple<int, string, char>(7, "doggy here", 'f');//create and assign
    cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;
    t2 = make_tuple(8, "cat here", 'g');//std lib provide a convinient function to make tuple
    cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;
    if(t>t2){
        t = t2;//member by member copy	
    }

    //tuple can store references, no other container in std can do it(can copy or move but reference)
    string st = "get a life";
    tuple<string&> t3(st);
    get<0>(t3) = "get an apple";
    cout << st << endl;

    t2 = make_tuple(21, "xxx xxx", 'a');
    int x;
    string y;
    char z;
    make_tuple(ref(x), ref(y), ref(z)) = t2;
    cout << x << " " << y << " " << z << " " << endl;

    //the same with support ignore 
    int xx;
    string yy;
    char zz;
    tie(xx, yy, zz) = t2;
    //tie(xx, std::ignore, zz) = t2;
    cout << xx << " " << yy << " " << zz << " " << endl;

    auto t4 = tuple_cat(t2, t3); //t4 is a tuple<int, string ,char, string>
    //type trait
    cout << tuple_size<decltype(t4)>::value << endl; //4
    //the element 1 in type t4 is type string
    tuple_element<1,decltype(t4)>::type d; //d is a string
    d = "this is a string";
    cout << d << endl;


}
