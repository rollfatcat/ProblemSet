// 喬瑟夫問題變形，給定總人數和最後一個活下來的號碼，詢問最少的skip可以讓最後一個號碼和輸入的一樣
// DP解最後一個存活者的號碼+枚舉skip
/* 因為題目規定一開始都是先移除1號，再隔m個人移除m號 -> 視為(n-1)個人的喬瑟夫問題，第一次移除m-1號
 * 輸入的最後存活者號碼對應回DP找出的最後存活者號碼要-2
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n,last; cin>>n>>last and n;){
    int m=2, f=0;
    for(n--; f!=last; m++){
      f=0; // 每一輪存活者一開始都是從0號開始
      for(int i=1;i<=n;i++)
        f=(f+m)%i;
      f+=2;// 對應回原本輸入的號碼
    }
    cout<<m-1<<'\n';
  }
}