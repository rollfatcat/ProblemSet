#include<iostream>
using namespace std;
#define MaxN 15

int n, m, bag[MaxN];
void DFS(int st, int now){
  if(now==m){
    if(m>0) cout<<'{'<<bag[0];
    else cout<<'{'<<0;
    for(int i=1;i<m;i++)
      cout<<','<<bag[i];
    cout<<'}'<<endl;
    return;
  }
  for(int i=st;i+(m-now)<=n;i++)
    bag[now]=i+1, DFS(i+1,now+1);
}

int main(){
  int T;

  cin>>T;
  while(T--){
    cin>>n;
    for(int i=0;i<=n;i++)
      m=i,
      DFS(0,0);
  }
}