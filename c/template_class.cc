#include <iostream>
using namespace std;

template <class T>
class Pair {
    private:
        T first, second;
    public:
        Pair (T a, T b):
        first(a), second(b) { }
        T bigger();
};

template <class T>
T Pair<T>::bigger() {
    return (first>second ? first : second);
}

int main()
{
    Pair <int> obj1(11, 22);
    cout << obj1.bigger() << endl;
    Pair <double> obj2(23.43, 5.68);
    cout << obj2.bigger() << endl;

    return 0;
}

