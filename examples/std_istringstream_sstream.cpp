#include <iostream>
#include <sstream>
// istringstream is for input, ostringstream for output. stringstream is input and output. You can use stringstream pretty much everywhere.
int main(){;
    std::string str = "true";
    bool boolValue;

    std::istringstream(str) >> std::boolalpha >> boolValue;
    std::cout << boolValue << std::endl;
}
