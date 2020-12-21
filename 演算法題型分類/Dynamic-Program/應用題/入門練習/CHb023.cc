#include<iostream>
using namespace std;

int N;
void Hanoi(int now,int st,int ed,int mid){
  if(now<=0)
    return;
  Hanoi(now-1,st,mid,ed);
  cout<<"Ring "<<now<<" from "<<st<<" to "<<ed<<endl;
  Hanoi(now-1,mid,ed,st);
}
int main(){
  while(cin>>N)
    Hanoi(N,1,3,2);
}