#include <iostream>
#include <vector>
#include <regex>
#include "pp.h"
using namespace std;


int main(){
    pppp("regex_search(str, smatch, regex)");

    string d = "Pi = 3.14, exponent = 2.718";
    string p = R"(\d+\.\d+)";
    regex re(p);
    smatch mt;
    //std::vector<std::string> values;
    vector<string> values;
    while (regex_search(d, mt, re)){
        ppp("smatch: ");
        for(auto s: mt) std::cout << s << " "; std::cout << std::endl;
        values.push_back(mt[0]);
        d = mt.suffix();
    }
    ppp("match result: ");
    for (string v: values) { std::cout << v << std::endl; }
}
