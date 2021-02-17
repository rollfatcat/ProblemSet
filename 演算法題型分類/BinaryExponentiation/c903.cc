// 解法：http://www.itdaan.com/blog/2017/08/07/a9d0163025bb.html
/* (2+√3)^n = An + √3*Bn
 * (2-√3)^n = An - √3*Bn
 * (2+√3)^n + (2-√3)^n = 2An 是整數，其中0< (2-√3)^n <1，是解题的關鍵。
 * 因為(2+√3)^n = 2An-(2-√3)^n，所以 (2+√3)^n 的整數部分就是 2*An-1.
 * 根据上面的推导，只要高效的求出An就可以解决这个问题了。
 * 因為 (3+√5)^(n+1) = (3+√5)(3+√5)^n = (3+√5)(An+√5*Bn)，我们可以得到An，Bn，A(n+1)，B(n+1)的遞迴關係。
 * A(n+1)=2An+3Bn；
 * B(n+1)= An+2Bn；
 * (A0,B0) = (1,0)
*/

#include<iostream>
#include<cmath>
using namespace std;
#define MOD 1000

int main(){
  for(int Np; cin>>Np;){
    long base[2][2][2]={ {{2,3},{1,2}} , {{1,1},{1,1}} };
    long vec[2][2]={{1,0},{1,1}};
    bool Bnow=1, Bpre, Vnow=1, Vpre;
    for(; Np>0; Np>>=1){
      Bpre=Bnow^1;
      if(Np&1){
        Vpre=Vnow^1;
        vec[Vnow][0]=(base[Bpre][0][0]*vec[Vpre][0]+base[Bpre][0][1]*vec[Vpre][1])%MOD;
        vec[Vnow][1]=(base[Bpre][1][0]*vec[Vpre][0]+base[Bpre][1][1]*vec[Vpre][1])%MOD;
        Vnow=Vpre;
      }
      base[Bnow][0][0]=(base[Bpre][0][0]*base[Bpre][0][0]+base[Bpre][0][1]*base[Bpre][1][0])%MOD;
      base[Bnow][0][1]=(base[Bpre][0][0]*base[Bpre][0][1]+base[Bpre][0][1]*base[Bpre][1][1])%MOD;
      base[Bnow][1][0]=(base[Bpre][1][0]*base[Bpre][0][0]+base[Bpre][1][1]*base[Bpre][1][0])%MOD;
      base[Bnow][1][1]=(base[Bpre][1][0]*base[Bpre][0][1]+base[Bpre][1][1]*base[Bpre][1][1])%MOD;
      Bnow=Bpre;
    }
    //輸出
    int ans=((vec[Vnow^1][0]<<1)-1)%1000;
    string ss;
    for(int i=0;i<3;i++,ans/=10)
      ss=(char)(ans%10+'0')+ss;
    cout<<ss<<endl;
  }
}
//