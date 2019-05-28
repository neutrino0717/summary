#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> numbers { 2, 3, 5, 7, 11, 13, 17 };
string str = "";
for (int i = 0; i < numbers.size(); i++)  {
    str += to_string(numbers[i]);
    if (i < numbers.size() - 1) {
        str += "; ";
    }
}
cout << str <<endl;
//str is "2; 3; 5; 7; 11; 13; 17"
}