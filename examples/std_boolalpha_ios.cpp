#include <iostream>
#include <sstream>
using namespace std;

int main(){
    // boolalpha output
    std::cout << std::boolalpha 
              << "boolalpha true: " << true << '\n'
              << "boolalpha false: " << false << '\n';
    std::cout << std::noboolalpha 
              << "noboolalpha true: " << true << '\n'
              << "noboolalpha false: " << false << '\n';
    // boolalpha parse
    bool b1, b2;
    std::istringstream is("true false");
    is >> std::boolalpha >> b1 >> b2;
    std::cout << '\"' << is.str() << "\" parsed as " << b1 << ' ' << b2 << '\n';


    bool sunIsStar = true;

    //the first method
    stringstream stream;
    stream  <<boolalpha<< sunIsStar;
    string str = stream.str();
    cout << str <<'\n';

    //the second method
    str = sunIsStar ? "true" : "false";
    cout << str <<'\n';

    //str is "true"
}
