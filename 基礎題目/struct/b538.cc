// 題目保證：除數不為０且分子分母都小於10,000
// 練習struct
#include<bits/stdc++.h>
using namespace std;

struct FRAC{
  int num, den;
  void reduce(void){ // (1)約分(2)分母是負的時，分子分母同時乘上-1s
    int GCD=__gcd(num,den);
    num/=GCD, den/=GCD;
    if(den<0) num=-num, den=-den;
  }
  void MULTI(FRAC &rhs){
    num*=rhs.num,
    den*=rhs.den,
    reduce();
  }
  void DIVIDE(FRAC &rhs){
    num*=rhs.den,
    den*=rhs.num,
    reduce();
  }
  void ADD(FRAC &rhs){
    num=num*rhs.den+rhs.num*den,
    den*=rhs.den,
    reduce();
  }
  void MINUS(FRAC &rhs){
    num=num*rhs.den-rhs.num*den,
    den*=rhs.den,
    reduce();
  }
  void PRINT(void){ // 輸出格式
    if(num==0)     { printf("0\n"); }
    else if(den==1){ printf("%d\n",num); }
    else           { printf("%d/%d\n",num,den); }
  }
}A, B;
int main(){

  char act;
  while(scanf("%d %d",&A.num,&A.den)==2){
    scanf("%d %d %c",&B.num,&B.den,&act);
    if(act=='+') A.ADD(B),   A.PRINT();
    if(act=='-') A.MINUS(B), A.PRINT();
    if(act=='*') A.MULTI(B), A.PRINT();
    if(act=='/') A.DIVIDE(B),A.PRINT();
  }
}
/*
-1 2 4 -3 +
1 1 1 1 -
1 1 1 2 +
2 3 1 2 *
2 3 2 3 /
*/