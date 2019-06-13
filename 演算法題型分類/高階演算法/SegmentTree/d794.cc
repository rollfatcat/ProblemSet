// 和d788的差別是成績遍佈的範圍是2^64-1，所以透過離散化的概念處理不連續性的問題
// 離散化：建表排序後，二分搜尋查詢數字是屬於哪一個位置
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, org[100000], num[100000], ST[300001], qR;
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int BS(int x){
  for(int l=0,r=N-1,m; l<=r;){
    m=(l+r)>>1;
    if(num[m]==x) return m;
    else if(num[m]>x) r=m-1;
    else l=m+1;
  }
}
int query(int l,int r,int idx){ // qL固定是1開始
  if(r<=qR) return ST[idx];
  int m=(l+r)>>1, lson=idx<<1, sum=query(l,m,lson);
  if(m<qR)  sum+=query(m+1,r,lson+1);
  return sum;
}
void OneNodeModify(int l,int r,int idx){
  ST[idx]++;
  if(l==r and l==qR) return;
  int m=(l+r)>>1, lson=idx<<1;
  if(m<qR) OneNodeModify(m+1,r,lson+1);
  else OneNodeModify(l,m,lson);
}
int main(){
  while(scanInt(N)){
    memset(ST,0,sizeof(ST));
    for(int i=0; i<N; i++)
        scanInt(num[i]), org[i]=num[i];
    sort(num,num+N);
    for(int x,t=1; t<=N; t++){
      x=BS(org[t-1])+1, qR=x,
      printf("%d\n",t-query(1,N,1)),
      OneNodeModify(1,N,1);
    }
  }
}