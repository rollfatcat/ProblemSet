// 容易錯在羅馬數字轉換成數字
// 將數字轉回羅馬數字的方式需要用到 STL 的 map

#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int RomanToInt(char c){
  switch(c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
  }
}
int SSToInt(string ss){
  // 不考慮非法輸入的情況下簡單判斷
  int stk[20]={};
  for(int i=0;i<ss.length();i++)
    stk[i]=RomanToInt(ss[i]);
  int out=0;
  for(int i=0;i<ss.length()-1;i++)
    out+=((stk[i+1]>stk[i])?-stk[i]:stk[i]);
  out+=stk[ss.length()-1];
  return out;
}
map<int, string>Dict={
  {1,"I"}, {2,"II"}, {3,"III"}, {4,"IV"}, {5,"V"}, {6,"VI"}, {7,"VII"}, {8,"VIII"}, {9,"IX"},
  {10,"X"}, {20,"XX"}, {30,"XXX"}, {40,"XL"}, {50,"L"}, {60,"LX"}, {70,"LXX"}, {80,"LXXX"}, {90,"XC"},
  {100,"C"}, {200,"CC"}, {300,"CCC"}, {400,"CD"}, {500,"D"}, {600,"DC"}, {700,"DCC"}, {800,"DCCC"}, {900,"CM"},
  {1000,"M"}, {2000,"MM"}, {3000,"MMM"}
};
string IntToSS(int x){
  if(x==0)
    return "ZERO";
  int num[4], cnt=0;
  for(int base=1; x>=1;x/=10,base*=10)
    num[cnt++]=x%10*base;
  for(int i=0;i<cnt;i++)
    cout<<num[i];
  cout<<endl;
  string out="";
  while(--cnt>=0)
    out+=Dict[num[cnt]];
  return out;
}
int main(void){
  string s1, s2;
  while(cin>>s1){
    if(s1=="#")
      break;
    cin>>s2;
    cout<<IntToSS( abs(SSToInt(s1)-SSToInt(s2)) )<<endl;
  }

}