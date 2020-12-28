#include<iostream>
using namespace std;
#define MaxN 9

int n;
bool CanPick[MaxN];
int Pick[MaxN];

void DFS(int now){
  if(now==n+1){
    for(int i=1;i<=n;i++)
      cout<<Pick[i];
    cout<<endl;
    return;
  }
  for(int i=n;i>0;i--)
    if(CanPick[i]){
      Pick[now]=i;
      CanPick[i]=0;
      DFS(now+1);
      CanPick[i]=1;
    }
}

int main(){
  while(cin>>n)
    fill(CanPick,CanPick+n+1,1), DFS(1);
}