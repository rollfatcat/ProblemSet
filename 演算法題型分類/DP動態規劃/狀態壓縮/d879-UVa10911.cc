// 原版想法：https://blog.csdn.net/acm_lkl/article/details/46460541?utm_source=blogxgwz1 => 2.3s
// 『找到狀態中最後一個1』=> 1s
// iPut和jPut交換無效, 所以只要找一半即可 => 0.7s
// 最後一輪只剩兩個可以選的人其實就在一開始抓兩個人算距離時算好存入 => 0.6s
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 17
#define INF 0x7fffffff

int N;
int Book[1<<15+1]; // map查表(㏒N)會TLE,改用陣列查表O(1)
double x[MaxN], y[MaxN];
double DP[1<<17-1], dis[16][16];
double DisCount(int a, int b){ return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])); }
double StatusDP(int nowS){
  if(DP[nowS]==INF){
    for(int outS=nowS, iPut; outS; outS^=iPut){
      iPut=outS&-outS;
      for(int inS=nowS^iPut, jPut; inS; inS^=jPut){
        jPut=inS&(-inS);
        if(iPut<jPut)
          DP[nowS]=min(DP[nowS], StatusDP(nowS^iPut^jPut)+DP[iPut+jPut] );
      }
    }
  }
  return DP[nowS];
}
int main(){
  string ss;
  for(int i=0;i<16;i++)
    Book[1<<i]=i;
  for(int caseNum=1;cin>>N and N>0;caseNum++){
    N<<=1;
    for(int i=0;i<N;i++)
      cin>>ss>>x[i]>>y[i];
    int s=(1<<N)-1;  ///用n位全为1的二进制数表示每个人的配对情况
    DP[0]=0.0;
    for(int i=1;i<=s;i++)
      DP[i]=INF;
    for(int i=0;i<N;i++) //只跑一半所以距離也只要存 i<j的情況即可
      for(int j=i+1;j<N;j++)
        DP[(1<<i)|(1<<j)]=DisCount(i,j);
    printf("Case %d: %.2lf\n",caseNum,StatusDP(s));
  }
}