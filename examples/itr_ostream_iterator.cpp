#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	vector < int >numbers = { 1, 2, 3, 4, 5 };
	auto iterator = ostream_iterator < int, char >(cout, "; ");
	copy(numbers.begin(), numbers.end(), iterator);
	// printed: "1; 2; 3; 4; 5;"

	stringstream stream;
	iterator = ostream_iterator < int, char >(stream, "-");
	copy(numbers.begin(), numbers.end(), iterator);
	string str = stream.str();
	cout << str;
	// str is "1-2-3-4-5-"
	
	//vector<int> numbers {1, 2, 3};
ostream_iterator<int, char> out_iter (cout, ",");

copy(numbers.rbegin(),
    numbers.rend(),
    out_iter);
//printed: "3 2 1 "
} 