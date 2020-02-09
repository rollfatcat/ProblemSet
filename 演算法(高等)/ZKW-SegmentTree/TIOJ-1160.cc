// 離散化+單點修改+全域查詢

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
const int MAXM=1<<(__lg(MAXN)+1);
int org[MAXN];
int num[MAXN];
struct nn{
  int num=0, cnt=0;
  bool operator>(const nn &rhs)const{ return(cnt==rhs.cnt)?(num<rhs.num):(cnt>rhs.cnt); }
} zkw[(MAXM|1)<<1];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int N=0;
  while(scanInt(org[N]) and org[N])
    num[N]=org[N], N++;
  sort(num,num+N);

  int uniN=unique(num,num+N)-num;
  int M=1<<(__lg(uniN)+1);
  // ---建樹---
  for(int i=0;i<uniN;i++)
    zkw[i+1+M].num=num[i];

  for(int i=0;i<N;i++){
    // ---單點修改---
    int leaf=lower_bound(num,num+uniN,org[i])-num+M+1;
    zkw[leaf].cnt++;
    for(int pos=leaf; pos>1; pos>>=1)
      if(zkw[pos]>zkw[pos^1])
        zkw[pos>>1].num=zkw[pos].num,
        zkw[pos>>1].cnt=zkw[pos].cnt;
    // ---全域查詢---
    printf("%d %d\n",zkw[1].cnt,zkw[1].num);
  }
}