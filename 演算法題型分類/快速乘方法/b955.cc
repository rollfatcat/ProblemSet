// Query的次方項最大到2^63，所以只能快速幂次
// 滾動陣列
#include<iostream>
using namespace std;
#define mod 1000007 // 這個mod計算平方時會超過int範圍

int main(){

  long N, M, K, f0, f1, f2, Q, x;
  long v[2][3], m[2][3][3];
  bool now_m, now_v, pre_m, pre_v;
  while(scanf("%ld %ld %ld %ld %ld %ld",&N,&M,&K,&f0,&f1,&f2)!=EOF){
    for(scanf("%ld",&Q); Q--;){
      scanf("%ld",&x);
      v[0][0]=f0, v[0][1]=f1, v[0][2]=f2;
      // initial
      if(x<=2){ printf("%ld\n",v[0][x]); continue; }
      //
      m[0][0][0]=0, m[0][0][1]=1, m[0][0][2]=0;
      m[0][1][0]=0, m[0][1][1]=0, m[0][1][2]=1;
      m[0][2][0]=K, m[0][2][1]=M, m[0][2][2]=N;
      //
      now_m=now_v=1, pre_m=pre_v=0;
      for(x-=2; x>0; x>>=1){
        if(x&1){
          for(int i=0;i<3;i++)
            v[now_v][i]=(m[pre_m][i][0]*v[pre_v][0]+m[pre_m][i][1]*v[pre_v][1]+m[pre_m][i][2]*v[pre_v][2])%mod;
          pre_v=now_v, now_v=1^now_v;
        }
        for(int i=0;i<3;i++)
          for(int j=0;j<3;j++)
            m[now_m][i][j]=(m[pre_m][i][0]*m[pre_m][0][j]+m[pre_m][i][1]*m[pre_m][1][j]+m[pre_m][i][2]*m[pre_m][2][j])%mod;
        pre_m=now_m, now_m=1^now_m;
      }
      if(v[pre_v][2]<0) v[pre_v][2]+=mod;
      printf("%ld\n",v[pre_v][2]);
    }
  }
}