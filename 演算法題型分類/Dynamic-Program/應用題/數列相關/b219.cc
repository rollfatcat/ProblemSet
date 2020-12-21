// 難在找到DP解法
// 當前面 N-1個排程已經排列好這時要插入 Nth排程, 可以選擇的位置是 N-1個
// 前面的 N-2個合法排程中(N-1)th黏在(N-2)th後面，原本是非法的但這時 Nth排程放入這兩個號碼當中就變合法
// 上述的 (N-2)th 可以出現的位置有 N-2種可能
#include<iostream>
using namespace std;

int pos[3][3]={{0,2,1},{1,0,2},{2,1,0}};
int main(){
  cin.sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n,m; cin>>n>>m;){
    if(n<3){ cout<<1%m<<endl; continue; }
    long DP[3]={0,1,1};
    for(int i=3;i<=n;i++)
      DP[ pos[i%3][0] ]=(DP[ pos[i%3][1] ]*(i-1)+DP[ pos[i%3][2] ]*(i-2))%m;
    cout<<DP[ pos[n%3][0] ]<<endl;
  }
}