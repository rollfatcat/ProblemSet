// 類似d879的配對組合 => 一次選兩個並保證A>B即可
// 狀態壓縮去挑選配對：0.1s
#include<iostream>
#include<iomanip>
#include<set>
using namespace std;

set<long> L[80];
void Permutate(int A,int B,int nowS){
  if(nowS==0){  if(A%B==0)  L[A/B].insert((long)100000*A+B);  return; }
  //__builtin_ctz(x):回傳後面幾個0
  // 一次挑兩個，然後交換(只有第一次就決定A/B大小)
  for(int outS=nowS, aS, aPut; outS; outS^=aS){
    aS=outS&-outS, aPut=__builtin_ctz(aS);
    for(int inS=nowS^aS, bS, bPut; inS; inS^=bS)
      bS=inS&-inS, bPut=__builtin_ctz(bS),
      Permutate(10*A+aPut,10*B+bPut,nowS^aS^bS),
      Permutate(10*A+bPut,10*B+aPut,nowS^aS^bS);
  }
}
inline void PrintL(long x,int a){
  string ans="";
  for(int i=0;i<5;i++,x/=10)
    ans=(char)(x%10+'0')+ans;
  ans=" / "+ans;
  for(int i=0;i<5;i++,x/=10)
    ans=(char)(x%10+'0')+ans;
  cout<<ans<<" = "<<a<<endl;
}
int main(){
  int allS=(1<<10)-1;
  for(int aPut=9; aPut>0; aPut--)
    for(int bPut=aPut-1; bPut>=0; bPut--)
      Permutate(aPut,bPut,allS^(1<<aPut)^(1<<bPut));
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n; cin>>n and n;)
    if(L[n].size())
      for(auto it:L[n])
        PrintL(it,n);
    else
      cout<<"There are no solutions for "<<n<<"."<<endl;
}