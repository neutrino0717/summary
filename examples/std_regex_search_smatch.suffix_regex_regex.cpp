#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main()
{
    string data = "Pi = 3.14, exponent = 2.718, done.";
    string pattern =  R"(\d+\.\d+)";
    regex regex(pattern);
    smatch match;
    vector < string > values;
    while (regex_search(data, match, regex))
    {
        values.push_back(match[0]);
        data = match.suffix();
        cout<<"the rest:"<<data<<endl;
    }
    // values is {3.14, 2.718}
    for(string x:values) cout<<x<<endl;
}
