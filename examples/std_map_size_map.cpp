#include <iostream>
#include <map>
using namespace std;

int main(){
    //init with some data
    map<int, string>  d = {
        {1, "one"}, {2, "two"}
    };

    long count = d.size();
    //count is 2
    cout << count << endl;
}
