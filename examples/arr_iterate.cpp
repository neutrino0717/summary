
#include <iostream>
#include <vector>
using namespace std;

void printNumber(int i)
{
	cout << i << "; ";

}

int main()
{
	int numbers1[] = { 2, 3, 5, 7 };
	string str = "";
  for (int number:numbers1)
	{
		cout << number << ";";
	}

	vector < int >numbers2
	{
	7, 11, 13};
	for_each(numbers2.begin(), numbers2.end(), printNumber);

  for (const int &u:numbers2)	// best, no copy
		std::cout << u << ";";
}