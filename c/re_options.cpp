#include <iostream>
#include <regex>
using namespace std;


int main(){
    string d = "AaaA\r\naaaA";
    string p = "^(a+)";
    regex re(p, regex::icase);
    smatch mt;
    //regex_match(d1, mt, re);  //for whole match
    bool b = regex_search(d, mt, re); 
    std::cout << b << endl;
    std::cout << mt[0] << endl;
    std::cout << mt[1] << endl;
}
