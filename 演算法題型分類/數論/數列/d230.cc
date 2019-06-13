// 卡塔蘭數列可以計算異構的二元樹個數的數量，本題是求異構三元樹的個數
// 一般卡塔蘭數：T(n)＝ΣT(n-1-i)*T(i), 0 ≦ i ≦ n-1，公式解：T(n)=C( 2*n,n )/(n+1)
// 既然一般卡塔蘭數是計算異構二元樹，那異構K元樹則可推導廣義卡塔蘭數列：T(n)=C( K*n,n )/( (K-1)*n+1)
// 運用公式解模擬上下約分的情況(0.2s)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define MOD 10000000

int main(){

  int N, GCD;
  scanf("%d",&N);
  vector<int> num;
  for(int i=2;i<=N;i++)
    num.push_back((N<<1)+i);
  for(int i=2;i<=N;i++){
    int Nnow=i, GCD;
    for(int i=0;i<num.size();){
      GCD=__gcd(num[i],Nnow);
      if(GCD>1) num[i]/=GCD, Nnow/=GCD;
      if(num[i]==1) num.erase(num.begin()+i);
      else i++;
      if(Nnow==1) break;
    }
  }
  long ans=1;
  for(int v:num)
    ans=ans*v%MOD;
  printf("%ld\n",ans);
}