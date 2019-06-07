#include <iostream>
//functional for C++98 
#include <functional>
using namespace std;

int main(){
    
auto avg = [](int a, int b) { return (a + b)/2; };
int n1 = avg(1, 3);
//n1 is 2

auto curriedAvg = [avg](int& a) {
    function<int(int)> f = [&](int b) { return avg(a, b);};
    return f;
};
int i7=7;
auto avgwith7 = curriedAvg(i7);
cout << avgwith7(17)<< endl;
//todo
}