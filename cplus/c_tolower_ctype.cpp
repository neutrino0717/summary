#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str = "Lower and upper";

    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower); //::tolower global namespace, which is tolower of C lauguage
    cout << lower << endl; //lower is "lower and upper"

    string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    cout << upper << endl; //upper is "LOWER AND UPPER"

}
