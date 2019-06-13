// 題目只保證給予 1e5 個數字且範圍落在 int 以內(測資的數字含有負數) => 離散化
// 逆數對的計算：(標準BIT模板解法)，同樣可以用CDQ解
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;
int org[MAXN], ord[MAXN];
int BIT[MAXN];
inline int lowbit(int x){ return -x&x; }
inline bool scanInt(int &x){
  char c=getchar();
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
int main(){

  for(int N,caseN=1; scanInt(N) and N;caseN++){
    for(int i=0;i<N;i++)
      scanInt(org[i]), ord[i]=org[i];
    sort(ord,ord+N);

    memset(BIT,0,sizeof(BIT));
    long ans=0;
    for(int i=0;i<N;i++){
      int pos=lower_bound(ord,ord+N,org[i])-ord+1;
      // ---區間查詢：查詢比現在數字大的數---
      int sumN=0;
      for(int j=pos; j; j-=lowbit(j))
        sumN+=BIT[j];
      ans+=i-sumN;
      // ---單點更新---
      for(int j=pos;j<=N;j+=lowbit(j))
        BIT[j]++;
    }
    printf("Case #%d: %ld\n",caseN,ans);
  }
}
/*
5
-1 -2 -3 -4 -5
*/