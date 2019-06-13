/* 不到最後一刻不認輸的猜數字遊戲
 * 輸入一個數字代表答案(範圍落在0-100之間)
 * 根據『二分逼近法』都拿中間值猜看看試答案直到範圍內剩下一個數字為止。
 */

#include<bits/stdc++.h>
using namespace std;

int ans;
bool BeMore(int x){ return x>=ans; } // 給他猜的數字只會說有沒有比答案還要大(或等於)
int main(){
  for(ans=0;ans<=100;ans++){
    int nL=0, nR=100, nM;
    int t=0;
    while(nL<nR){ //當nL=nR時，代表只存在一個數字他就是『唯一』答案
      nM=nL+nR>>1;
      if(BeMore(nM))
        nR=nM;
      else
        nL=nM+1;
      t++;
    }
    cout<<t<<" : "<<nL<<' '<<nM<<' '<<nR<<endl;
  }
}