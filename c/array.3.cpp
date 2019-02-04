#include <iostream>
using namespace std;

int main()
{
    //int a[5];
    int arr[] = {11, 35, 62, 555, 989};
    int sum = 0; 
    for (int x = 0; x < 5; x++)  sum += arr[x];  //1652
    cout << sum << endl;

    int x[2][3] = {{2, 3, 4}, {8, 9, 10}};
    cout << x[0][2] << endl;                    //4

    return 0;
}
