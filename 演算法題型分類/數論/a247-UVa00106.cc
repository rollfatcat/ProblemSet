// 很難,不是短時間內可以做出來的數論題(主要是時間限制太高)
// 這一題有兩個重點：(1)能不能快速找到全部的平方組合 (2)預跑時就抓到全部的答案
// (1) A^2+B^2=C^2 => A^2=x^2-y^2, B^2=2*x*y, C^2=x^2+y^2
// (1) 做法是用兩層for迴圈產生全部的可能組合即可, 組合有個特性是(i,j)必為一偶一奇, 所以窮舉時 i+=1,j+=2
// (2) 找到一組合(並且找出MaxN內的倍數關係組合)就紀錄"範圍至少要多少才會出現這組解答",範圍由C決定
// (2) ans[0][x]:在x範圍內的『互質』解個數, ans[1][x]：在x範圍內的有解的個數
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define INF 0x7f7f7f7f

//注意全域變數的空間可以宣告比較大(ans不能放在區域變數)
int until[MAXN]; // until[x]: 範圍至少要到x才會被包含在內
int ans[2][MAXN]={};// ans[0][x]:在x範圍內的『互質』解個數, ans[1][x]：在x範圍內的有解的個數
int main(){

  memset(until,0x7f,sizeof(until));
  int bound=sqrt(MAXN);
  for(int i=1;i<bound;i++)
    for(int j=i+1; true;j+=2){
      if(__gcd(i,j)>1) continue;
      int A2=j*j-i*i,
          B2=2*i*j,
          C2=j*j+i*i ;
      if(C2>=MAXN) break;
      ans[0][C2]++;
      for(int k=1;k*C2<MAXN;k++)
        until[k*A2]=min(until[k*A2],k*C2),
        until[k*B2]=min(until[k*B2],k*C2),
        until[k*C2]=min(until[k*C2],k*C2);
    }
  for(int i=1;i<=MAXN;i++){
    ans[0][i]+=ans[0][i-1];
    if(until[i]<=MAXN)  ans[1][ until[i] ]++;
    ans[1][i]+=ans[1][i-1];
  }
  for(int N; scanf("%d",&N)!=EOF; )
    printf("%d %d\n",ans[0][N],N-ans[1][N]);
}