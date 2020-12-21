// 輸出 費波納契數列的模數
#include<iostream>
using namespace std;
#define MOD 1000000007

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  long DP[10001]={1,1,2,3};
  for(int i=4;i<=10000;i++)
    DP[i]=(DP[i-1]+DP[i-2])%MOD;
  for(int n; scanInt(n); )
    printf("%ld\n",DP[n]);
}
