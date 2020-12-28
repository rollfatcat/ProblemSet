// DFS＋限制展開條件
#include<iostream>
#include<cstring>
using namespace std;

bool isPrime[32]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
bool use[17];
int n, ring[16];
void DFS(int now){
  if(now==n){
    if(isPrime[1+ring[n-1]]){
      for(int i=0;i<n;i++)
        cout<<ring[i]<<' ';
      cout<<'\n';
    }
    return;
  }
  for(int i=2;i<=n;i++)
    if(isPrime[ring[now-1]+i] and use[i]==0){
      ring[now]=i;
      use[i]=1;
      DFS(now+1);
      use[i]=0;
    }
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int caseNum=1;cin>>n;caseNum++){
    cout<<"Case "<<caseNum<<":\n";
    memset(use,0,sizeof(use));
    ring[0]=use[1]=1;
    DFS(1);
    cout<<'\n';
  }
}