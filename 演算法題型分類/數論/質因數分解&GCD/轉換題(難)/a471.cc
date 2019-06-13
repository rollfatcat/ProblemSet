// 數論實作題：d756-uva10290(這題的加強版)
// 連續整數區間和的梯形公式：(2a+x-1)*x/2=N, 分解N的所有因數組合
// 而且(2a+x-1)>x, 所以只要嘗試 x<sqrt(2N) 內的所有因數即可, 答案要反向輸出
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define MaxP 10001


bool isPrime[MaxP]={0};
vector<int> base, power, fac;
void DFS(int now,int num){
  if(now==base.size())  return;
  DFS(now+1,num);
  for(int i=0;i<power[now];i++)
    num*=base[now], fac.push_back(num), DFS(now+1,num);
}
int main(){
  int bound=10000;
  vector<int> prime;
  // 建質數表
  for(int j=4;j<=bound;j+=2)
    isPrime[j]=1;
  for(int i=3;i<=100;i+=2)
    if(!isPrime[i])
      for(int j=i<<1;j<=bound;j+=i)
        isPrime[j]=1;
  for(int j=2;j<=bound;j++)
    if(!isPrime[j])
      prime.push_back(j);

  for(int N, cnt; cin>>N; ){
    base.clear(), power.clear(), fac.clear();
    int n=N<<1, brk;
    for(int j=0, p;j<prime.size() and j<=sqrt(n) and n>1; j++)
      if(n%prime[j]==0){
        for(p=0;n%prime[j]==0;p++,n/=prime[j]);
        base.push_back(prime[j]), power.push_back(p);
      }
    if(n>1) base.push_back(n), power.push_back(1);
    DFS(0,1);
    sort(fac.begin(),fac.end());
    n=N<<1, brk=sqrt(n), cnt=0;
    vector<int> Nst, Ned;
    for(int i=0;fac[i]<=brk;i++){
      int A=n/fac[i]+1-fac[i];
      if(A%2==0) //題目要反向輸出,所以先存在vector
        cnt++, Nst.push_back(A/2), Ned.push_back(A/2+fac[i]-1);
    }
    if(cnt==0)
      printf("No Solution...\n\n");
    else{
      for(int i=Nst.size()-1;i>=0;i--)
        printf("%d-%d\n",Nst[i],Ned[i]);
      printf("\n");
    }
  }
}