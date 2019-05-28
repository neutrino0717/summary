#include <iostream>
#include <vector>
#include <valarray>
using namespace std;

int main()
{
	 vector < int >numbers {1, 2, 3, 4, 5};
 	transform(numbers.begin(),numbers.end(),numbers.begin(), [&](int i) { return i * 3; });
	// numbers is [ 3, 6, 9, 12, 15 ]
    for (const int &v: numbers)std::cout << v << std::endl;
    
	valarray < int >numbers2{1, 2, 3, 4, 5};
	numbers2 = (numbers2 + 2) * 2;
	// numbers2 is [ 6, 8, 10, 12, 14 ]
    for (const int &v: numbers2)std::cout << v << std::endl;
}