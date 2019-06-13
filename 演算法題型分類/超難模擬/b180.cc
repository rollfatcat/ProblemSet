#include<bits/stdc++.h>
using namespace std;

const int oo=1<<30;
int N, ANS;
struct cc{
  int st,on,id;
  bool operator<(const cc other)const{return(st==other.st)?(id<other.id):(st<other.st);}
} custom[60], tmp[60];
int bike[60]; // bike[idx]:紀錄第idx輛腳踏車下一次回到出發站的時間
void DFS(int now,int bike_n){
  if(now==N){
    if(bike_n<ANS)
      ANS=bike_n;
    return;
  }
  if(bike_n>=ANS) // 剪枝
    return;
  int idx, rec;
  for(idx=0; idx<bike_n; idx++){
    if(bike[idx]<custom[now].st+30){ // 枚舉第now位客人能搭上的腳踏車
      rec=bike[idx]; // 先保留第idx輛腳踏車上一次紀錄的時間數據
      if(bike[idx]>=custom[now].st) // 人已經排隊後，腳踏車才還回來
        bike[idx]=bike[idx]+custom[now].on;
      else // 腳踏車已經先到站，人後來才到
        bike[idx]=custom[now].st+custom[now].on;
      DFS(now+1,bike_n); // 修改完後往下遞迴
      bike[idx]=rec; // 回覆第idx輛腳踏車上一次紀錄的時間數據
    }
  }
  // 直接給一輛新的腳踏車作為使用，注意call的順序是最後才有剪枝的意義
  bike[bike_n]=custom[now].st+custom[now].on;
  DFS(now+1,bike_n+1);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N){
    for(int i=0;i<N;i++)
      cin>>custom[i].st>>custom[i].on, custom[i].id=i;
    sort(custom,custom+N);
    ANS=oo;
    DFS(0,0);
    cout<<ANS<<'\n';
  }
}