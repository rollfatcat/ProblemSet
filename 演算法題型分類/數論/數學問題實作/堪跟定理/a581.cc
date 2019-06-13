// 堪根定理＋二分法(相等時輸出答案)
#include<bits/stdc++.h>
using namespace std;

// 這題要四捨五入到小數點第四位(第五位決定，所以定第六位)
// 不過第477筆測資會出現錯誤，所以往下改到第7位 或者固定train 100回合。
const double ESP=1e-7;
int p, r;       // 0 ≦ p,r ≦ 20
int q, s, t, u; // -20 ≦ q,s,t ≦ 0

inline double Func(double x){ return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u; }
inline bool TwoSide(double vL,double vR){ return (vL>0.0 and vR<0.0) or (vL<0.0 and vR>0.0); }
int main(){
  while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6){
    // init
    double nL=0.0, vL=Func(nL);
    if(vL==0.0){ puts("0.0000");continue; }
    double nR=1.0, vR=Func(nR);
    if(vR==0.0){ puts("1.0000");continue; }

    if(TwoSide(vL,vR)){
      double nM, vM;
      while(nR-nL>=ESP){
        nM=(nL+nR)/2.0,
        vM=Func(nM);
        if(vM==0.0) printf("%lf\n",vM);
        else (TwoSide(vL,vM))? nR=nM: nL=nM;
      }
      printf("%.4lf\n",nM);
    }
    else
      puts("No solution");
  }
}
/*
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
*/