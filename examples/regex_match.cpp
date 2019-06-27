#include <iostream>
#include <regex>
using namespace std;

int main()
{
	string data1 = "aaab";
	string data2 = "aaaba";
	string pattern = "a+b";
	regex regex(pattern);
	smatch match;
	//match the whole string
	bool b1 = regex_match(data1, match, regex);
	bool b2 = regex_match(data2, match, regex);
	cout << b1<<b2<<endl;
}