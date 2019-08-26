#include <iostream>
#include <sstream>
using namespace std;

int main(){

    stringstream ss;

    ss << "hex of 89 is: " << hex << 89 << ". oct of 89 is: " << oct << 89;
    cout << ss.str() << endl;
}
