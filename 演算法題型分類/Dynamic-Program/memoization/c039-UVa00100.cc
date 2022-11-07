// 過程中的數值狀態會超過int可負擔範圍，需使用long，且最大深度 524
// 線性計算=>DP的方式避開重複計算  0.3s=>8ms
#include<iostream>
using namespace std;

int deep[1000001]={0,1};
int DFS(long now){
  if(now<=1000000){ //計算過程中不重複算過的部分
    if(!deep[now])
      deep[now]=DFS( (now&1)?(3*now+1):(now>>1) )+1;
    return deep[now];
  }
  return DFS( (now&1)?(3*now+1):(now>>1) )+1;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int idx=2; idx<=1000000; idx++)
    if(!deep[idx])
      deep[idx]=DFS( (idx&1)?(3*idx+1):(idx>>1) )+1;
  for(int l,r; cin>>l>>r; ){
    cout<<l<<' '<<r<<' ';
    if(l>r) l^=r^=l^=r;
    int maxD=deep[l];
    for(int i=l+1;i<=r;i++)
      maxD=max(maxD,deep[i]);
    cout<<maxD<<endl;
  }
}