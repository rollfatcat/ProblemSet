/* 題目給定方程式，在 ０ ≦ ｘ ≦ １ 內是否存在一個根(精確度輸出到小數點第四位)
 * 解題關鍵：堪根定理＋二分法
 * 注意計算時的精確度設定
 */
#include<bits/stdc++.h>
using namespace std;

/* 精確度設定
 * 這題要四捨五入到小數點第四位(第五位決定是否進位，所以定第六位)
 * 但第477筆測資會出現錯誤，所以往下改到第7位 或者固定train 100回合。
 */
const int MaxCaseT=2000;
const double ESP=1e-7;
int p, r;       //   0 ≦ ｐ,ｒ    ≦ 20
int q, s, t, u; // -20 ≦ ｑ,ｓ,ｔ ≦  0

inline double Func(double x){ return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u; }
inline bool TwoSide(double vL,double vR){ return (vL>ESP and vR<-ESP) or (vL<-ESP and vR>ESP); }
inline bool IsZero(double x){ return -ESP<= x and x<=ESP; }
int main(){
  while(scanf("%d %d %d %d %d %d\n",&p,&q,&r,&s,&t,&u)==6){
    /* 邊界值剛好是方程式的根 */
    double nL=0.0, vL=Func(nL);
    if(vL==0.0){ puts("0.0000");continue; }
    double nR=1.0, vR=Func(nR);
    if(vR==0.0){ puts("1.0000");continue; }
    /* 兩點的值落在同一邊＝範圍內根不存在 */
    if(TwoSide(vL,vR)==0){
      puts("No solution"); continue;
    }
    /* 二分法，停止條件：(1)左右邊界的差值小於最小單位 (2)中間點的ｙ值＝０ */
    double nM, vM;
    while(nR-nL>=ESP){
      nM=(nL+nR)/2.0,
      vM=Func(nM);
      if( IsZero(vM) ) break;
      (TwoSide(vL,vM))? nR=nM-ESP: nL=nM+ESP;
    }
    printf("%.4lf\n",nM);  
  }
}