#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
stack<int> s;
s.push(1);
s.push(3);
s.push(5);
queue<int> q;
q.push(1);
q.push(3);
q.push(5);

cout<<q.front() <<";"; q.pop();
cout<<q.front() <<";"; q.pop();
cout<<q.front() <<";"; q.pop();
cout<<endl;
cout<<s.top() <<";"; s.pop();
cout<<s.top() <<";"; s.pop();
cout<<s.top() <<";"; s.pop();
}