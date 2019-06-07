#include <iostream>
#include <regex>
using namespace std;


int main(){
    string d1 = "aaab";
    string d2 = "aaaba";
    string p = "a+ba";
    regex re(p);
    smatch mt;
    bool b1 = regex_match(d1, mt, re); 
    bool b2 = regex_match(d2, mt, re); 
    std::cout << b1 << endl;
    std::cout << b2 << endl;

   
}
