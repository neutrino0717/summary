#include <iostream>
#include <regex>
using namespace std;

int main()
{
	string data = "Pi = 3.14, exponent = 2.718, done.";
	string pattern = R"(\d+\.\d+)";
	regex regex(pattern);
	//regex regex(pattern, regex::icase);
	data = regex_replace(data, regex, "<f>$0</f>");
	cout << data << endl;
}