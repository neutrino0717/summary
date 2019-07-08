#include <iostream>
using namespace std;

string reverse(string word) {
    //Characters count
    int charCount = (int)word.length();
    string result = "";
    for (int i = charCount - 1; i >= 0; i--)
    {
        result += word[i];
    }
    return result;
}

int main(){

string stringReverse = reverse("string");
//stringReverse = "gnirts"
cout << stringReverse;

}