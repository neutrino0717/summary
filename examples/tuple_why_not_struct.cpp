#include <iostream>
#include <tuple>
using namespace std;

int main(){
    struct Person { string name; int age; } p;
    tuple<string, int> t;

    cout << p.name << " " << p.age << endl;
    cout << get<0>(t) << " " << get<1>(t) << endl;


}
