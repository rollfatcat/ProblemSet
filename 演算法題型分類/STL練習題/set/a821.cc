// STL Set和 iterator的練習
#include<iostream>
#include<set>
using namespace std;

int main(){
  for(int N,R; cin>>N>>R;){
    set<string> A, B, C;
    string ssA, ssB;
    for(int i=0;i<R;i++){
      cin>>ssA>>ssB;
      if(!A.count(ssA)) A.insert(ssA);
      if(!B.count(ssB)) B.insert(ssB);
    }
    set<string>::iterator itA, itB;
    for(itA=A.begin(); itA!=A.end(); itA++){
      for(itB=B.begin(); itB!=B.end() and *itB!=*itA; itB++);
      if(itB==B.end()){
        cout<<*itA<<endl; break;
      }
    }
 }
}
/*
3 3
tpa azf
tpa abc
azf abc
*/