// 找到4個連續的數，這4個數分別都是4個不同的質數構成
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime, p2;
int main(){
  // 建質數表(足夠判斷整數範圍內)
  int bound=sqrt(0x7fffffff);
  vector<bool> isP(bound+1,true);
  for(int i=4;i<=bound;i+=2)
    isP[i]=false;
  for(int i=3;i<=sqrt(bound);i+=2)
    if(isP[i])
      for(int k=(i<<1),j=k+i; j<=bound; j+=k)
        isP[j]=false;
  for(int i=2;i<=bound;i++)
    if(isP[i])
      prime.push_back(i), p2.push_back(i*i);

  int idx, i, Ncnt, Pcnt, num;
  for(idx=211, Ncnt=1; Ncnt<4; idx++){
    Pcnt=0;
    for(i=0,num=idx; p2[i]<=num and num>1; i++)
      if(num%prime[i]==0)
        for(Pcnt++; num%prime[i]==0; num/=prime[i]);
    if(num>1) Pcnt++;
    if(Pcnt>=4) Ncnt++;
    else  Ncnt=0;
  }
  cout<<idx-4<<endl;
}