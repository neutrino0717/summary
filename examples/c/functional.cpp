#include <iostream>
//functional for C++98 
#include <functional>
using namespace std;

int main(){
    
 
auto makeWallet = [](int &sum)
{
    function<int(int pay)> f = [&](int pay) -> int {
        sum -= pay;
        return sum;
    };
    return f;
};
  
int sum1000 = 1000;

//a wallet with 1000 yuan
auto payFromWallet1 = makeWallet(sum1000);
int sum500 = 500;

//a wallet with 500 yuan
auto payFromWallet2 = makeWallet(sum500);

//captures the last passed value (500)
cout << "balance: " << payFromWallet1(50) <<endl;
//balance is 950
cout << "balance: " << payFromWallet2(70) <<endl;
//balance is 430


}