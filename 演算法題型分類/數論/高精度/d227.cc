// 高精確度
#include<iostream>
#include<cmath>
using namespace std;

const double esp=1e-8;
const double PI=acos(-1);

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  
  for(double a; cin>>a;){
    double x=a/180.0*PI, bitx=1.0, sinx=0.0;
    int p=1;
    for(; true ;p++){
      bitx*=(x/p);
      if(p%2){
        sinx+=((p%4==1)?bitx:-bitx);
        if(abs(bitx)<0.01+esp) break;
      }
    }
    printf("N = %d\n%.6lf\n",p,sinx);
  }
}