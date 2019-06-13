// 可以用巴斯卡三角形的DP解
// 或是利用 GCD() 把數字作約分之後保證乘積不會超過上限
#include<iostream>
#include<vector>
using namespace std;

int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  int N, M, cnt;

  while(cin>>N>>M and N and M){
    printf("%d things taken %d at a time is ",N,M);
    M=max(N-M,M), cnt=N-M;
    vector<int> num;
    for(int i=M+1;i<=N;i++)
      num.push_back(i);
    for(int i=2;i<=cnt;i++)
      for(int j=0, n=i;j<cnt and n>1;j++){
        int gcd=(n>num[j])?GCD(n,num[j]):GCD(num[j],n);
        if(gcd>1) n/=gcd, num[j]/=gcd;
      }
    unsigned long long int ans=1;
    for(int i=0;i<cnt;i++)
      ans*=num[i];
    printf("%llu exactly.\n",ans);
  }
}