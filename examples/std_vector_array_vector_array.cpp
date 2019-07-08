#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    //Empty array;
    vector<int> n1;

    // Single-dimensional array
    array<int, 3> n2 = { 1, 2, 3 };
    vector<int> n3 { 1, 2, 3 };
    string s1[] { "1", "2", "3" };

    // Multidimensional array.
    int n4[2][2] = {{1, 2}, {4, 5}};
    int n5[2][3] = {1, 2, 3, 4, 5, 6};
    n5[1][2] = 7;

    // Jagged array
    vector<vector<int>> n6 = {{ 1, 2 }, {3, 4, 5 }};
    using namespace std;


    for (const int &u: n3) cout << u << ";";
}
