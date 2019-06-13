// 流程控制，輸出格式是測資之間空一行(嚴格比對)
// 利用陣列紀錄每一個電器是否開啟並判斷某個時刻是否超過電流上限

#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int t[21], load, MaxLoad;
  int n, m, c, x;
  bool on[21];

  for(int caseN=1; cin>>n>>m>>c and n and c; caseN++){
    if(caseN>1) cout<<endl<<endl;
    for(int i=1;i<=n;i++)
      cin>>t[i], on[i]=false;
    cout<<"Sequence "<<caseN<<endl;
    for(MaxLoad=load=0; m; m--){
      cin>>x;
      if(!on[x]){
        load+=t[x], on[x]=1;
        if(load>c){ cout<<"Fuse was blown."; break; }
        if(load>MaxLoad) MaxLoad=load;
      } else load-=t[x], on[x]=0;
    }
    if(m==0)
      cout<<"Fuse was not blown."<<endl,
      cout<<"Maximal power consumption was "<<MaxLoad<<" amperes.";
    else
      while(--m) cin>>x; //完成剩下沒讀取的部分
  }
}