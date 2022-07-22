// 和d788的差別是成績遍佈的範圍是2^64-1，所以透過離散化的概念處理不連續性的問題
// 離散化：建表排序後，二分搜尋查詢數字是屬於哪一個位置
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, org[100000], num[100000],BIT[100001]={};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
int BS(int x){
  for(int l=0,r=N-1,m; l<=r;){
    m=(l+r)>>1;
    if(num[m]==x) return m;
    else if(num[m]>x) r=m-1;
    else l=m+1;
  }
}
int main(){
  while(scanInt(N)){
    memset(BIT,0,sizeof(BIT));
    for(int i=0; i<N; i++)
        scanInt(num[i]), org[i]=num[i];
    sort(num,num+N);
    for(int x,t=1; t<=N; t++){
      x=BS(org[t-1])+1;
      // query_sum
      int query_sum=0;
      for(int i=x;i>0; i-=lowbit(i))
        query_sum+=BIT[i];
      printf("%d\n",t-query_sum);
      // update
      for(int i=x;i<=N;i+=lowbit(i))
        BIT[i]+=1;
    }
  }
}