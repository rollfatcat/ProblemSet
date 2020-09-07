// if 可以過，但是請練習BinarySearch
// 找不到時歸類給左邊界
#include<iostream>
#include<iomanip>
using namespace std;

double num[8]={-0.35,-0.250, 0.0, 0.25, 0.5, 1.0, 1.5, 2.0};
string level="OBAFGKM";
char BS(double x){
  int l=0, r=7, m;
  while(l<=r){
    m=(l+r)>>1;
    if(num[m]==x) return level[m];
    else if(num[m]>x) r=m-1;
    else l=m+1;
  }
  return level[r];
}
int main(){
  string ss;
  double mB, mV;

  while(cin>>ss and ss!="END")
    cin>>mB>>mV, cout<<ss<<' '<<setiosflags(ios::fixed)<<setprecision(2)<<mB-mV<<' '<<BS(mB-mV)<<endl;
}
/*
VEGA 0.00 0.00
PROCYON 0.80 0.38
SOL 5.48 4.83
END
*/