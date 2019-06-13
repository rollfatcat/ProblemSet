// 解題關鍵：讓問題的『區間因數個數和』具有『單調性』=> 前綴和
//

#include<iostream>
#include<vector>
using namespace std;
#define MAXN 100005

int sumn[MAXN][4];
int prime[4]={};
int Pcnt[4]={};
int Tcnt[4]={};
int sz=0;

inline void GetPrime(int K){
  if(K%2==0){ prime[sz]=2; while(K%2==0) Pcnt[sz]++, K/=2; sz++; }
  if(K%3==0){ prime[sz]=3; while(K%3==0) Pcnt[sz]++, K/=3; sz++; }
  if(K%5==0){ prime[sz]=5; while(K%5==0) Pcnt[sz]++, K/=5; sz++; }
  if(K%7==0){ prime[sz]=7; while(K%7==0) Pcnt[sz]++, K/=7; sz++; }
  if(K>1){ prime[sz]=K; Pcnt[sz]=1; sz++; }
}
inline void factor(int K,int now){
  for(int p,i=0;i<sz;i++){
    for(p=0;K%prime[i]==0;K/=prime[i],p++);
    sumn[now][i]=sumn[now-1][i]+p;
  }
}
inline bool IsLess(int now){
  for(int i=0;i<sz;i++)
    if(sumn[now][i]<Tcnt[i])
      return true;
  return false;
}
int main(){
  int N, K, x;
  cin>>N>>K;
  // 分解需要的質數和對應的個數
  GetPrime(K);
  // 對每個輸入的數字計算前綴和
  for(int i=1;i<=N;i++)
    cin>>x, factor(x,i);
  /* 從最左端點出發，根據目前的向量個數＋需要的，找到最遠的右端點
   * 從右端點開始數到最後代表都是具有足夠數量個數的因數(也就是Ｋ倍)，加總計算即可。
   * 而且因為具有遞增性，下一次開始時就從上一次的點出發找到滿足條件的右端點(線性完成搜索)
   */
  long long cnt=0;
  int pivot=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<sz;j++)
      Tcnt[j]=sumn[i][j]+Pcnt[j];
    while( pivot<=N and IsLess(pivot) )
      pivot++;
    cnt+=N-pivot+1;
  }
  cout<<cnt<<endl;
}