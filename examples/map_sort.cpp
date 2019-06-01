#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
map<int, string>  dic = {
    { 3, "C" }, { 1, "B" }, { 2, "A" }};
    for(auto &iter: dic) cout <<iter.first << iter.second<<endl;
//sort by key dic
    sort(dic.begin(), dic.end(), [&](pair<int,string> p1, pair<int,string> p2){ return p1.second < p2.second; });
    for(auto &iter: dic) cout <<iter.first << iter.second<<endl;
 //todo
//sort by value
}