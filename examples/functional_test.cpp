#include <iostream> 
#include "math.h"
//for C++98 
#include <functional>
using namespace std;
int main(){
//only explicitly specify return type
function<int(int)> powOfTwo = [](int power) { return (int)pow(2, power); };
auto                       powOfThree = [](double power) { return pow(3, power); };

cout << powOfTwo(8) <<";" << powOfThree(3);
}
