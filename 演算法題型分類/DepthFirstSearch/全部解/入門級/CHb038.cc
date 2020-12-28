#include<iostream>
using namespace std;

int bag[8], n;
bool canPick[8];
void DFS(int now){
  if(now==n){
    for(int i=0;i<n;i++)
      cout<<bag[i];
    cout<<endl;
    return;
  }
  for(int i=0;i<n;i++)
    if(canPick[i]){
      bag[now]=i+1;
      canPick[i]=0;
      DFS(now+1);
      canPick[i]=1;
    }
}
int main(){
  while(cin>>n)
    fill(canPick,canPick+n,1), DFS(0);
}