// 利用排容原理, 練習n個數字選m個, 並且一邊計算最小倍數
// 想法很簡單, 但是寫成DFS需要想一下...
#include<iostream>
#include<vector>
using namespace std;

int M, N, num[15], Layerall;
long GCD(long a, long b){ return (a%b)?GCD(b,a%b):b; }
void Pick(int now, int st, long LCM){
  // 計算過程中發現, 最小公倍數已經超過N, 代表不用再展開
  if(LCM>N) return;
  // 球選完之後,就計算在N以內的倍數個數
  if(now==0){ Layerall+=(N/LCM); return; }
  for(int i=st;i<=(M-now);i++)
    Pick(now-1,i+1,LCM*num[i]/GCD(LCM,num[i]));
}
int main(){
  while(cin>>N>>M and N and M){
    for(int i=0;i<M;i++)
      cin>>num[i];
    int ans=N;
    for(int i=1;i<=M;i++)
      Layerall=0,  Pick(i,0,1),  ans+=((i%2)?-Layerall:Layerall);
    cout<<ans<<endl;
  }
}