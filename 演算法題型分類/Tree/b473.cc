/* 題目保證輸入的是網路結構是樹狀(#edge=#node-1) #node=2e5
 * 輸出所有點對(間隔距離=2)的加權值相乘總和和最大的乘積
 * 乍看下以為是要圖論去找出所有點對，但點的數量太多會吃TLE...
 * 關鍵：間隔距離=2的點對，與其枚舉起點和終點，不如枚舉『中點』與中點相連的點中任選兩個即是起/終點。
 * 加權值乘積總和：利用乘法的分配率(將其它的加權值加起來後乘上該項加權值)
 * 最大乘積：保留前兩個最大的加權值即可
 * 上述的關鍵概念也應用在 UVa-01428 ，枚舉所有的『中間點』
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=200001;
const int MOD=10007;
int wght[MAXN];
vector<int> Link[MAXN];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int nodeN, u, v;
  scanInt(nodeN);
  for(int i=1;i<nodeN;i++)
    scanInt(u),
    scanInt(v),
    Link[u].push_back(v),
    Link[v].push_back(u);
  for(int i=1;i<=nodeN;i++)
    scanInt(wght[i]);
  long sum=0;
  int best=0;
  for(int i=1;i<=nodeN;i++)
    if(Link[i].size()>1){
      long cont=wght[Link[i][0]]+wght[Link[i][1]];
      int maxv[3]={ wght[Link[i][0]],wght[Link[i][1]] };
      if(maxv[0]<maxv[1]) swap(maxv[0],maxv[1]);
      for(int j=2;j<Link[i].size();j++){
        cont+=wght[ Link[i][j] ];
        maxv[2]=wght[ Link[i][j] ];
        if(maxv[1]<maxv[2]) swap(maxv[1],maxv[2]);
        if(maxv[0]<maxv[1]) swap(maxv[0],maxv[1]);
      }
      best=max(best,maxv[0]*maxv[1]);
      for(int j=0;j<Link[i].size();j++)
        sum+=wght[ Link[i][j] ]*(cont-wght[ Link[i][j] ]);
    }
  printf("%d %ld\n",best,sum%MOD);
}
/*
5
1 2
2 3
3 4
4 5
1 5 2 3 10
*/