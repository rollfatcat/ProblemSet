/* 這題因為空間限制在64MB，原本以為無法用SparseTable(一般情況下空間是N㏒N)做
 * 但仔細觀察可以發現Query的區間是固定且只問一次，所以只要保留SparseTable裡面 h=__lg(w)即可
 * 且每個陣列存放的值是機率，範圍落在(0,100) => 用short存值就好
 * Query 成本和空間可以同時降低(300ms => 75ms)
 */
#include<bits/stdc++.h>
using namespace std;
#define MaxN 300000

short maxST[MaxN], minST[MaxN];
inline bool scanInt(short &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
int main(){

  for(int N,w; scanf("%d %d",&N,&w)==2 and N; ){
    for(int i=0;i<N;i++)
      scanInt(maxST[i]), minST[i]=maxST[i];
    // Build SparseTable
    int h_ST=__lg(w);
    for(int h=0;h<h_ST;h++)
      for(int st=0; st+(1<<h)<N; st++)
        maxST[st]=max(maxST[st],maxST[st+(1<<h)]),
        minST[st]=min(minST[st],minST[st+(1<<h)]);
    //
    vector<int> ans;
    short recD=0x7fff;
    for(int st=0; st+w<=N; st++){
      short maxD=max(maxST[st],maxST[st+w-(1<<h_ST)]);
      short minD=min(minST[st],minST[st+w-(1<<h_ST)]);
      short tmpD=maxD-minD;
      if(recD>tmpD) recD=tmpD, ans.clear();
      if(recD==tmpD) ans.push_back(st+1);
    }
    printf("%lu\n",ans.size());
    for(int i=0;i<ans.size();i++)
      printf("%d %d\n",ans[i],ans[i]+w-1);
  }
}