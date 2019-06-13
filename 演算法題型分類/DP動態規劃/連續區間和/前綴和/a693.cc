// 需要加速讀取和輸出
// !EOF的說明 和  scanf("%lld")和longlong的關係
#include<iostream>
using namespace std;
#define MaxN 100001

int main(){
  int n, m;
  int num[MaxN];
  long long int sum[MaxN];
  int l,r;
  while(scanf("%d%d",&n,&m)!=EOF){
    sum[0]=0;
    for(int i=0;i<n;i++)
      scanf("%d",&num[i]),
      sum[i+1]=sum[i]+num[i];
    while(m--)
      scanf("%d%d",&l,&r),
      printf("%lld\n",sum[r]-sum[l-1]);
  }
}