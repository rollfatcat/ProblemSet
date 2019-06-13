// 大數快速乘法(base=1e3)＋大數加法的應用 => 72ms
#include<bits/stdc++.h>
using namespace std;

const int base=1e3;
vector<int> NumB, NumS;
void NumFastPower(int Nbase,int Npower){ //快速乘方法
  vector<int> Nt(1,((Npower&1)?Nbase:1) );
  vector<int> Bs(1,Nbase);
  for(Npower>>=1; Npower; Npower>>=1){
    // 底數平方
    vector<int> tmp(Bs.size()<<1,0);
    for(int i=0;i<Bs.size();i++)
      for(int j=0;j<Bs.size();j++)
        tmp[i+j]+=Bs[i]*Bs[j];
    int carry=0;
    for(int i=0;i<tmp.size();i++)
      tmp[i]+=carry, carry=tmp[i]/base, tmp[i]%=base;
    while(tmp.back()==0) tmp.pop_back();
    Bs=tmp;
    //
    if(Npower&1){
      tmp.assign(Bs.size()+Nt.size(),0);
      for(int i=0;i<Bs.size();i++)
        for(int j=0;j<Nt.size();j++)
          tmp[i+j]+=Bs[i]*Nt[j];
      int carry=0;
      for(int i=0;i<tmp.size();i++)
        tmp[i]+=carry, carry=tmp[i]/base, tmp[i]%=base;
      while(tmp.back()==0) tmp.pop_back();
      Nt=tmp;
    }
  }
  NumB=Nt;
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
  for(int i=2;i<=999;i++)
    NumFastPower(i,i),
    NumAdd(NumB);
  // 把1000額外獨立出來相加，方便快速乘方法可以搭配 base=1e3 加速
  NumS.push_back(0), NumS.push_back(1);
  printf("%d",NumS.back());
  for(int i=NumS.size()-2;i>=0;i--)
    printf("%03d",NumS[i]);
  puts("");
}
// 10405071317
// 10405071317