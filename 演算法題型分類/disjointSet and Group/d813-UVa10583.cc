#include<bits/stdc++.h>
using namespace std;

const int maxN=5e4+1;
int N, parent[maxN], cnt[maxN];
// ---測資間數字的空白可能不只一個，也可能參雜換行---
inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
int find_parent(int x){
  if(parent[x]!=x)
    parent[x]=find_parent(parent[x]);
  return parent[x];
}
int main(){
  for(int M,caseN=1; scanInt(N) and scanInt(M) and N;caseN++){
    for(int i=1;i<=N;i++)
      parent[i]=i, cnt[i]=1;
    int groupCnt=N;
    for(int a,b; M--;){
      scanInt(a), scanInt(b);
      int Pa=find_parent(a),
          Pb=find_parent(b);
      // ---不同群 => Union---
      if(Pa!=Pb){
        groupCnt--;
        if(Pa>Pb) // ---預設指向數字小的當作Parent---
          Pa^=Pb^=Pa^=Pb;
        parent[Pb]=Pa, cnt[Pa]+=cnt[Pb];
      }
    }
    printf("Case %d: %d\n",caseN,groupCnt);
  }
}