// 計算 n! 的質因數個數，前綴和的技巧，完成後可以做 d423-uva10856 還需要二分法
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MaxN 1000001

int main(){
  bool isPrime[MaxN];
  memset(isPrime,0xff,sizeof(isPrime));
  isPrime[0]=isPrime[1]=0;
  // 找到1000以下的質數就可以推出1000000以內的質數
  vector<int> prime;
  for(int i=2;i<32;i++)
    if(isPrime[i]){
      prime.push_back(i);
      for(int j=2;i*j<=1000;j++)
        isPrime[i*j]=0;
    }
  for(int i=32;i<=1000;i++)
    if(isPrime[i])
      prime.push_back(i);
  //
  int cnt[MaxN]={0};
  cnt[0]=cnt[1]=0;
  for(int i=2;i<=1000000;i++){
    int num=i, p;
    for(int j=0;j<prime.size() and num>1;j++){
      for(p=0;num%prime[j]==0;num/=prime[j]) p++;
      cnt[i]+=p;
    }
    if(num>1) cnt[i]++;
    cnt[i]+=cnt[i-1];
  }

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n;cin>>n;)
    cout<<cnt[n]<<'\n';
}