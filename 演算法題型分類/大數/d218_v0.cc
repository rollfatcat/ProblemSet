// 假大數乘法＋大數加法的應用 => 0.3s

#include<bits/stdc++.h>
using namespace std;

const int base=1e4;
vector<int> NumB, NumS;
void NumPower(int Nbase,int Npower){ //最大是1000^1000，就不用快速乘方法
  NumB.clear(), NumB.push_back(Nbase);
  for(Npower--;Npower--;){
    int carry=0;
    for(int i=0;i<NumB.size();i++)
      NumB[i]=NumB[i]*Nbase+carry, carry=NumB[i]/base, NumB[i]%=base;
    if(carry) NumB.push_back(carry);
  }
}
void NumAdd(vector<int> &B){ // 預設B比較大
  for(int i=B.size()-NumS.size();i>0;i--)
    NumS.push_back(0);
  int carry=0;
  for(int i=0;i<NumS.size();i++)
    NumS[i]=NumS[i]+B[i]+carry, carry=NumS[i]/base, NumS[i]%=base;
  if(carry) NumS.push_back(carry);
}
int main(){
  NumS.push_back(1);
  for(int i=2;i<=1000;i++)
    NumPower(i,i),
    NumAdd(NumB);
  printf("%d",NumS.back());
  for(int i=NumS.size()-2;i>=0;i--)
    printf("%04d",NumS[i]);
  puts("");
}