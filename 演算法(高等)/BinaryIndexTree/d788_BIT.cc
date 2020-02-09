// BinaryIndexTree version
/* 提示：題目保證成績介於 1 ≦ M ≦ N ，且每個人的成績都不重複
 * 關鍵：每次輸入成績時，統計(1,M)前有幾個人，名次=全部人數減掉目前成績前的總人數
 */
#include<iostream>
#include<cstring>
using namespace std;

int N, BIT[100001]={};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
int main(){
  while(scanInt(N)){
    memset(BIT,0,sizeof(BIT));
    for(int x,t=1; t<=N; t++){
      scanInt(x);
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