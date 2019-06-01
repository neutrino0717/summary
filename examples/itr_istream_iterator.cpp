#include <iostream>
#include <sstream>
using namespace std;

int main(){
string str = "1 2 3 4 5";
stringstream stream(str);
int numbers[5];

copy(istream_iterator<int, char>(stream),
    istream_iterator<int, char>(),
    numbers);
//numbers in {1, 2, 3, 4, 5}
for(int &i: numbers) cout << i << ":";
}