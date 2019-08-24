#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string>  dic = {
        {1, "one"}, {2, "two"}
    };

    bool exists1 = dic.find(1) != dic.end(); //exists1 is 1
    cout << exists1 << endl;

    bool exists2 = dic.find(2) != dic.end(); //exists2 is 1
    cout << exists2 << endl;

    bool exists3 = dic.find(3) != dic.end(); //exists3 is 0
    cout << exists3 << endl;
}
