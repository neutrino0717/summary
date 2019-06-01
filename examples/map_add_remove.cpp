#include <iostream>
#include <map>
using namespace std;

int main(){
map<int, string> dic;
dic[1] = "one";
dic[2] = "two";
dic[3] = "tree";
//dic is {{1, "one"}, {2, "two"}, {3, "tree"}}

dic[3] = "three";
//dic is {{1, "one"}, {2, "two"}, {3, "three"}}

dic.erase(3);
//dic is {{1, "one"}, {2, "two"}}
for(auto iter = dic.begin(); iter != dic.end(); ++iter) cout <<iter->first << iter->second<<endl;
for(auto &iter: dic) cout <<iter.first << iter.second<<endl;

dic.clear();
//dic is empty

for(auto iter = dic.begin(); iter != dic.end(); ++iter) cout <<iter->first << iter->second<<endl;

}
