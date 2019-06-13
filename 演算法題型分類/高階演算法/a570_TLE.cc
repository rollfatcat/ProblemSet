// 題目要在使用時段不重複的情況下最大化收益
// N<=3000，類似 a449 的烏龜王國公車，只是 DP 儲存的最佳狀態直接存在該線段的價值上
// 烏龜王國公車那題的作法是O(n^2) => 0.6s
#include<bits/stdc++.h>
using namespace std;

const int MAXN=3000;
struct LINE{
  int st, ed, val;
  bool operator<(const LINE &rhs)const{ return st<rhs.st; }
}PQST[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N;scanInt(N);){
    for(int i=0;i<N;i++)
      scanInt(PQST[i].st),
      scanInt(PQST[i].ed),
      scanInt(PQST[i].val);
    sort(PQST,PQST+N);
    int ans=0;
    for(int i=0;i<N;i++){
      int prev=0;
      for(int j=0;j<i;j++)
        if(PQST[j].ed<=PQST[i].st)
          prev=max(prev,PQST[j].val);
      PQST[i].val+=prev;
      ans=max(ans,PQST[i].val);
    }
    printf("%d\n",ans);
  }
}
/*
4
1 3 5
2 5 6
4 7 3
6 9 4
2
1 2 3
2 3 6
*/