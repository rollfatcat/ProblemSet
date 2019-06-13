// 取兩個點，讓所有點到兩個點的最短距離總和最少化
// 單一個點時問題就是曼哈頓距離最小化，題目是兩個點時(?)
// 核心作法：枚舉決定分群的節點(這個點以左包含該點為一群，以右為一群)
// 測資範圍：2 ≤ N ≤ 1e5，0 ≤ Xi ≤ 1e9

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int pos[MAXN];
long sum[MAXN];
int main(){
  int N;
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>pos[i];
  sort(pos,pos+N+1);
  // 前綴和
  for(int i=1;i<=N;i++)
    sum[i]=sum[i-1]+pos[i];
  // 枚舉分群的節點，只要小於等於這個節點的為一群否則是另一群
  // 利用前綴和快速求出兩群的中心點和距離總和
  long min_sum=sum[N];
  for(int i=1;i<N;i++){
    int mL=(1+i)>>1;
    int mR=(N+i+1)>>1;
    long dL=pos[mL]*(mL-1)-sum[mL-1]+sum[i]-sum[mL]-pos[mL]*(i-mL);
    long dR=pos[mR]*(mR-i-1)-sum[mR-1]+sum[i]+sum[N]-sum[mR]-pos[mR]*(N-mR);
    min_sum=min(min_sum,dL+dR);
  }
  cout<<(min_sum<<1)<<endl;

}