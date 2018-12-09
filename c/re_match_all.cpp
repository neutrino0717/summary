#include <iostream>
#include <vector>
#include <regex>
using namespace std;


int main(){
    string d = "Pi = 3.14, exponent = 2.718";
    string p = R"(\d+\.\d+)";
    regex re(p);
    smatch mt;
    //std::vector<std::string> values;
    vector<string> values;
    while (regex_search(d, mt, re)){
        values.push_back(mt[0]);
        d = mt.suffix();
    }
    for (string v: values) { std::cout << v << std::endl; }
}
