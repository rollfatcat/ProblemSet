// List的STL練習
#include<iostream>
#include<algorithm> // for find(start,end,key)
#include<list>
using namespace std;

int main(){
  string action, ss;
  list<string> ll;
  while(cin>>action and action!="SHOW"){
    cin>>ss;
    if(action=="ADD")
      ll.push_back(ss);
    else if(action=="REMOVE")
      ll.erase(find(ll.begin(),ll.end(),ss));
    else
      cin>>action, ll.insert(find(ll.begin(),ll.end(),action),ss);
  }
  for(list<string>::iterator it=ll.begin(); it!=ll.end();it++)
    cout<<*it<<' ';
  cout<<endl;
}