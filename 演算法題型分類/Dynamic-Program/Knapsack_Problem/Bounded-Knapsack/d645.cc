// 有限背包混雜0/1背包的練習題
/* 為何可以將有限背包問題透過物品數量『二進位化』等價成0/1背包問題
 * 注意『二進位化』的定義是 13＝1+2+4+6，而不是 13＝1+4+8
 * 前者的二進位化可以保證在這項物品中取Ｋ件一定可以由二進位化構成，後者並不保證
 */
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 1001

int main(){
  int N, W;
  int v, w, t;
  int map[MaxN];
  memset(map,0,sizeof(map));

  cin>>N>>W;
  for(int i=0;i<N;i++){
    cin>>v>>w>>t;
    if(t==-1)
      for(int j=w;j<=W;j++)
        map[j]=max(map[j],map[j-w]+v);
    else{ //有限背包,把數量t 二進位化變成0/1背包問題
      int num=min(t,W/w);
      for(int k=1; num>0; k*=2){
        if(k>num)
          k=num;
        num-=k;
        for(int j=W; j>=w*k; j--)
          map[j]=max(map[j], map[j-w*k]+v*k);
      }
    }
  }
  cout<<map[W]<<endl;
}