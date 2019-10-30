#include <iostream>
#include <algorithm>
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
    for (int number:numbers1) { cout << number << ";"; }; cout << endl;

    vector < int >numbers2 { 7, 11, 13};
    std::for_each(numbers2.begin(), numbers2.end(), printNumber); cout << endl;
	// best, no copy
    for (const int& u:numbers2) std::cout << u << ";"; cout << endl;
}
