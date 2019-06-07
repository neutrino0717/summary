#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
using namespace std;

int  pp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '=')  << s << std::string(pad2, '=') << "\n";
}

int  ppp(std::string s) {
    int len = 80;
    int pad1 = (len - s.length()) / 2;
    int pad2 = len - pad1 - s.length();
    std::cout << "\n" << std::string(pad1, '-')  << s << std::string(pad2, '-') << "\n";
}

//void foo(const unordered_map<char, string>& m) {
void foo(unordered_map<char, string>& m) {
    //m['S'] = "SUNDAY";
    cout << m['S'] << endl;
    //auto itr = m.find('S');
    //if (itr != m.end()) cout << *itr << endl;
}


int main() {
    pp("vector");
    cout << "Properties of Vector:\n"
            "1. fast insert/remove at the end: O(1)\n"
            "2. slow insert/remove at the begining or in the middle: O(n)\n"
            "3. slow search: O(n)\n";
    vector<int> vec;   // vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);  // vec: {4, 1, 8};    vec.size() == 3
    std::cout << "1. vector size:" << vec.size() <<  std::endl;

    ppp("vector specific operations:");
    cout << vec[2] <<endl;     // 8  (no range check)
    cout << vec[5] <<endl;     // ramdon
    cout << vec.at(2) << endl;  // 8  (throw range_error exception of out of range)

    for (int i; i < vec.size(); i++) cout << vec[i] << " ";  //4 1 8
    for (vector<int>::iterator itr1 = vec.begin(); itr1!= vec.end(); ++itr1) cout << *itr1 << " ";  ////4 1 8
    for (auto it: vec) cout << it << " "; cout << endl; // 4 1 8  C++ 11

    ppp("Vector is a dynamically allocated contiguous array in memory");
    int* p = &vec[0];   p[2] = 6;
    for (auto it: vec) cout << it << " "; cout << endl;

    pp("Common member functions of all containers.");
    //vec: {4, 1, 8}
    if ( ! vec.empty()) { cout << "not empty.\n"; }
    if ( not vec.empty()) { cout << "not empty.\n"; }
    cout << vec.size() << endl;   // 3
    ppp("Copy constructor");
    vector<int> vec2(vec);  // Copy constructor, vec2: {4, 1, 8}
    vec.clear();    // Remove all items in vec;   vec.size() == 0
    vec2.swap(vec);   // vec2 becomes empty, and vec has 3 items.

    vector<int> vec5 = {1,2,3,4};
    int* p2 = &vec5[2];   // p points to 3
    cout << *p2 << endl;   // 2, or ?
    vec5.insert(vec5.begin(), 0);
    cout << *p2 << endl;   // -2144354360, myview: the vec5 addresses changed
    for(auto vv:vec5) cout << vv << " ";

    pp("Deque");

    cout << "Properties of Deque:\n"
            "1. fast insert/remove at the beginning and the end;\n"
            "2. slow insert/remove in the middle: O(n)\n"
            "3. slow search: O(n)\n";


    deque<int> deq = { 4, 6, 7 };
    deq.push_front(2);  // deq: {2, 4, 6, 7}
    deq.push_back(3);   // deq: {2, 4, 6, 7, 3}
    for(auto d: deq) cout << d << " ";

    ppp("Deque has similar interface with vector");
    cout << deq[1];  // 4

    pp("list -- double linked list");
    cout << " Properties:\n"
            " 1. fast insert/remove at any place: O(1)\n"
            " 2. slow search: O(n)\n"
            " 3. no random access, no [] operator.\n";

    list<int> mylist = {5, 2, 9 };
    mylist.push_back(6);  // mylist: { 5, 2, 9, 6}
    mylist.push_front(4); // mylist: { 4, 5, 2, 9, 6}
    for(auto e: mylist) cout << e << " ";

    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
    cout << endl;
    mylist.insert(itr, 8);   // mylist: {4, 5, 8, 2, 9, 6}
    // O(1), faster than vector/deque
    itr++;                   // itr -> 9
    mylist.erase(itr);       // mylist: {4, 8, 5, 2, 6}   O(1)
    for(int e2: mylist) cout << e2 << " ";

    //mylist1.splice(itr, mylist2, itr_a, itr_b );   // O(1)

    cout << "Associative Container\n"
            "1. Always sorted, default criteria is <\n"
            "2. No push_back(), push_front()\n";
    pp("set - No duplicates");
    cout << "Properties:\n"
            "1. Fast search: O(log(n))\n"
            "2. Traversing is slow (compared to vector & deque)\n"
            "3. No random access, no [] operator.\n";
    set<int> myset;
    myset.insert(3);    // myset: {3}
    myset.insert(1);    // myset: {1, 3}
    myset.insert(7);    // myset: {1, 3, 7},  O(log(n))
    set<int>::iterator it;
    it = myset.find(7);  // O(log(n)), it points to 7
    cout << *it << endl;
    // Sequence containers don't even have find() member function
    pair<set<int>::iterator, bool> ret;
    ret = myset.insert(3);  // no new element inserted
    if (ret.second==false) it=ret.first;       // "it" now points to element 3
    myset.insert(it, 9);  // myset:  {1, 3, 7, 9}   O(log(n)) => O(1)
    for(auto aint: myset) cout << aint << " "; cout << endl;
    // it points to 3
    myset.erase(it);         // myset:  {1, 7, 9}
    for(auto aint: myset) cout << aint << " "; cout << endl;
    myset.erase(7);   // myset:  {1, 9}
    for(auto aint: myset) cout << aint << " "; cout << endl;
    // Note: none of the sequence containers provide this kind of erase.

    pp("multiset is a set that allows duplicated items");
    multiset<int> mymset;

    // set/multiset: value of the elements cannot be modified
    //*it = 10;  // *it is read-only

    pp("map - No duplicated kedy");
    map<char,int> mymap;
    mymap.insert ( pair<char,int>('a',100) );
    mymap.insert ( make_pair('z',200) );

    map<char,int>::iterator itm = mymap.begin();
    //mymap.insert(pair<char,int>('b',300));  // "it" is a hint
    mymap.insert(itm, pair<char,int>('b',300));  // "it" is a hint

    itm = mymap.find('z');  cout << (*itm).first <<" => "<<(*itm).second << endl; // O(log(n))

    ppp("showing contents:");
    for ( itm=mymap.begin() ; itm != mymap.end(); itm++ ) cout << (*itm).first << " => " << (*itm).second << endl;

    pp("multimap is a map that allows duplicated keys");
    multimap<char,int> mymmap;

    // map/multimap:
    //  -- keys cannot be modified
    //     type of *it:   pair<const char, int>
    //(*it).first = 'd';  // Error

    // Associative Containers: set, multiset, map, multimap
    //
    // What does "Associative" mean?

    cout << " *  Unordered Container (C++ 11)\n"
            " *   - Unordered set and multiset\n"
            " *   - Unordered map and multimap\n"
            " *  Order not defined, and may change overtime\n"
            " *  Default hash function defined for fundamental types and string.\n"
            " *  No subscript operator[] or at()\n"
            " *  No push_back(), push_front()\n"
            " */";


    pp("unordered set");
    unordered_set<string> myuset = { "red","green","blue" };
    unordered_set<string>::const_iterator citr = myuset.find ("green"); // O(1)
    if (citr != myuset.end()) cout << *citr << endl; // Important check
    myuset.insert("yellow");  // O(1)
    vector<string> vec3 = {"purple", "pink"};
    myuset.insert(vec3.begin(), vec3.end());
    for (auto x: myuset) cout << x << " ";

    ppp("Hash table specific APIs:");
    cout << "load_factor = " << myuset.load_factor() << endl;
    string x = "red";
    cout << x << " is in bucket #" << myuset.bucket(x) << endl;
    cout << "Total bucket #" << myuset.bucket_count() << endl;

    pp("map and unordered map");
    unordered_map<char, string> day = {{'S',"Sunday"}, {'M',"Monday"}};

    cout << day['S'] << endl;    // No range check
    cout << day.at('S') << endl; // Has range check

    day['W'] = "Wednesday";  // Inserting {'W', "Wednesday}
    day.insert(make_pair('F', "Friday"));  // Inserting {'F', "Friday"}

    day.insert(make_pair('M', "MONDAY"));  // Fail to modify, it's an unordered_map
    day['M'] = "MONDAY";                   // Succeed to modify
    //wrong unordered cannot ++
    //nordered_map<char,string>::iterator itmm;
    //for ( itmm=day.begin() ; itmm != mymap.end(); itmm++ ) cout << (*itmm).first << " => " << (*itm).second << endl;
    for(auto itmm: day) cout << itmm.first <<"==>" << itmm.second << endl;

    unordered_map<char, string>& m = day;
    //m['S'] = "SUNDAY";
    cout << day['S'] << endl;
    cout << m['S'] << endl;
    auto itr4 = m.find('S');
    if (itr4 != m.end() ) cout << itr4->second << endl;

    foo(day);

    pp("Array");
    int a[3] = {3, 4, 5};
    array<int, 3> a2 = {3, 4, 5};
    a2.begin();
    a2.end();
    a2.size();
    array<int, 3> a3 = { 6, 7, 8};
    a2.swap(a3);
    array<int, 4> b = {3, 4, 5};

    cout << "/*\n"
            " * Container Adaptor\n"
            " *  - Provide a restricted interface to meet special needs\n"
            " *  - Implemented with fundamental container classes\n"
            " *\n"
            " *  1. stack:  LIFO, push(), pop(), top()\n"
            " *\n"
            " *  2. queue:  FIFO, push(), pop(), front(), back() \n"
            " *\n"
            " *  3. priority queue: first item always has the greatest priority\n"
            " *                   push(), pop(), top()\n"
            " */\n";
    cout << "/*\n"
            " * Another way of categorizing containers:\n"
            " *\n"
            " * 1. Array based containers: vector, deque\n"
            " *\n"
            " * 2. Node base containers: list + associative containers + unordered containers\n"
            " *\n"
            " * Array based containers invalidates pointers:\n"
            " *    - Native pointers, iterators, references\n"
            " */\n";

    pp("Iterators");

    ppp("1. Random Access Iterator:  vector, deque, array");
    vector<int> v6 = {1,2,3,4,5,6,7,8};
    vector<int>::iterator itr6 = v6.begin();
    itr6 = itr6 + 5; cout << *itr6;  // advance itr by 5
    itr6 = itr6 - 4; cout << *itr6;
    //if (itr2 > itr1) ...
    ++itr6;   cout << *itr6;// faster than itr6++
    --itr6;

    ppp("2. Bidirectional Iterator: list, set/multiset, map/multimap");
    list<int> l7= {1,2,3,4,5};
    list<int>::iterator itr7 = l7.begin();
    ++itr7; cout << *itr7;
    --itr7; cout << *itr7;

    ppp("3. Forward Iterator: forward_list");
    // Unordered containers provide "at least" forward iterators.
    forward_list<int> f1 = {1,2,3,4};
    forward_list<int>::iterator itrf = f1.begin();
    ++itrf; cout << *itrf;



}
