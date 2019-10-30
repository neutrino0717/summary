#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
/*
sequence (arrays, linkedlist)  -- vector, deque, list, forward list, array
#include <vector>
#include <deque>
#include <list>       //linked list

associative (binary tree)      -- set, multiset, map, multimap
#include <set>
#include <map>

unordered (hash table)         -- unordered set/multiset; unordered map/multimap
#include <unordered_set>
#include <unordered_map>
                               -- others
#include <algorithm>
#include <numeric>      //some numeric algorithm
#include <functional>

         insert/remove insert/remove(end) search                        random access
vector   O(n)          O(1)               O(n)                          Y
deque    O(n)          O(1)(and begin)    O(n)                          Y
list     O(1)          O(1)               O(n)(slow for no cpu cache )  N
set      O(log(n))                        O(log(n))                     N


*/

using namespace std;

int main() {
    array<int, 3> a = { 5, 4, 3 }; //must be fix lengh, use vector should be better
    array<int, 4> b = { 5, 4, 3, 2 }; //a, b are different type, so should use vector
    vector<int> vec = { 9, 8 , 7};
    deque<int> deq = { 4, 6, 7 };
    list<int> lst = { 5 , 2, 9 };
    set<int> st = { 8, 7, 6 }; //no duplicates, elements read only
    multiset<int> mst = { 8, 7, 6 ,6}; //allow duplicate
    map<char, int> mp;
    multimap<char, int> mmp; //allow duplicate
 
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);
    deq.push_back(2);
    deq.push_front(8);
    list<int>::iterator itrl = find(lst.begin(), lst.end(), 2);
    lst.insert(itrl, 8); //fast
    lst.erase(itrl); //fast
    set<int>::iterator itrs = st.find(7); //itrs points to 7
    pair<set<int>::iterator, bool> ret = st.insert(3);  //no duplicate, no order
    if(ret.second == false) itrs = ret.first;  //insert OK, itrs points to 3
    st.insert(itrs, 9);// itrs is only a hint to reduce insert tim, from O(log(n)) to O(1)
    st.erase(itrs);
    st.erase(6);
    mp.insert(pair<char,int>('a', 100));
    mp.insert(make_pair('z',200));  //save types
    map<char, int>::iterator itrm = mp.find('z');


    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end();
    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr) cout << *itr << " "; cout << endl;
    for (int i=0; i < vec.size(); i++) { cout << vec[i] << " "; }; cout << endl; //slow
    for (deque<int>::iterator itrd = deq.begin(); itrd != deq.end(); ++itrd) cout << *itrd << " "; cout << endl;
    for (itrl = lst.begin(); itrl != lst.end(); ++itrl) cout << *itrl << " "; cout << endl;
    for (itrs = st.begin(); itrs != st.end(); ++itrs) cout << *itrs << " "; cout << endl;
    for (itrm = mp.begin(); itrm != mp.end(); ++itrm) cout << (*itrm).first << (*itrm).second << " "; cout << endl;

    sort (itr1, itr2);
    sort (deq.begin(), deq.end());
    //sort (lst.begin(), lst.end());  //error
    for (vector<int>::iterator itr = itr1; itr != itr2; ++itr) cout << *itr << " "; cout << endl;
    for (deque<int>::iterator itrd = deq.begin(); itrd != deq.end(); ++itrd) cout << *itrd << " "; cout << endl;
    int* p = &vec[0]; cout << p[2] << endl;  //dynamically allocated contiguous array in memory


    //common member functions
    cout << vec.empty() <<endl;
    cout << vec.size() <<endl;
    vector<int> vec2(vec);     //copy constructor
    vec.clear();
    vec2.swap(vec);
}
