/* 一開始以為要用『中國餘式定理』解這題，但可以發現測資可以直接暴力法解
 * 暴力法：嘗試所有的年份，輸出符合全部標準的最小答案
 * 此題為UVA題目，採嚴格比對，測資『之間』換行
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXY=10000;
int main(){
  int N, y[20], d[20];
  for(int caseN=0;scanf("%d",&N) and N;){
    if(caseN++) puts("");
    int ansY=0,a,b;
    for(int i=0;i<N;i++)
      scanf("%d %d %d",&y[i],&a,&b),
      d[i]=b-a,
      ansY=max(ansY,y[i]);
    for(int i=0; ansY<MAXY; ansY++){
      for(i=0;i<N and (ansY-y[i])%d[i]==0;i++);
      if(i==N) break;
    }
    if(ansY==MAXY) printf("Case #%d:\nUnknown bugs detected.\n",caseN);
    else printf("Case #%d:\nThe actual year is %d.\n",caseN,ansY);
  }
}