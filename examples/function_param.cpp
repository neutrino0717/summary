#include <iostream> 
//functional for C++98  
#include <functional>
using namespace std;

void checkAndProcessNumber (int number,
    function<void(int)> process) {
    if (number < 10) {
        process(number * 10);
    }
}

int main(){
auto process = [](int number) {
    cout << number;
};

checkAndProcessNumber(5, process);
//printed: 50
}