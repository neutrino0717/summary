#include <iostream> 
//functional for C++98  
#include <functional>
using namespace std;
//template< class R, class... Args >
//class function<R(Args...)>;  //R is return
void checkAndProcessNumber (int number, function<void(int)> process) 
{
    if (number < 10) {
        process(number * 10);
    }
}

int main(){
    auto process = [](int number) { cout << number << endl; };

    checkAndProcessNumber(5, process);
    //printed: 50
}
