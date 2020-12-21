// 原版想法：https://blog.csdn.net/acm_lkl/article/details/46460541?utm_source=blogxgwz1 => 2.3s
// 1.0s『找到狀態中最後一個1』
// 0.7s iPut和jPut交換無效, 所以只要找一半即可
// 0.6s 最後一輪只剩兩個可以選的人其實就在一開始抓兩個人算距離時算好存入
// 16ms iPut的選擇先後順序不影響結果，所以不需要for迴圈
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 17
#define INF 0x7fffffff

int N;
double x[MaxN], y[MaxN];
double DP[1<<17-1];
double DisCount(int a, int b){ return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])); }
double StatusDP(int nowS){
  if(DP[nowS]==INF){ // 選的順序不影響結果，故不需要第二層迴圈
    int iPut=nowS&-nowS;
    for(int inS=nowS^iPut, jPut; inS; inS^=jPut){
      jPut=inS&(-inS);
      if(iPut<jPut)
        DP[nowS]=min(DP[nowS], StatusDP(nowS^iPut^jPut)+DP[iPut|jPut] );
    }
  }
  return DP[nowS];
}
int main(){
  string ss;
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