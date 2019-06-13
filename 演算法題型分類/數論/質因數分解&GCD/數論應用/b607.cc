// 數論題：哥德巴赫猜想：(A)任一大於2的偶數都可寫成兩個質數之和 (B)任一大於5的奇數都可寫成三個質數之和
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

vector<bool> isP(1000001,1);
vector<int> prime, cnt;
int BS(int x){ // 二分搜尋找小於等於x的質數，注意回傳的是r
  int l=0, r=prime.size()-1, m;
  while(l<=r){
    m=(l+r)/2;
    if(prime[m]==x) return m;
    else if(prime[m]>x) r=m-1;
    else l=m+1;
  }
  return r;
}
void OddSum(int n){ //找到一組質數和=n, 且n必定是偶數
  for(int i=BS(n/2); i>=0;i--)
    if(isP[n-prime[i]]){
      cnt.push_back(prime[i]),  cnt.push_back(n-prime[i]);  return;
    }
}
void PrimeSum(int n){
  if(isP[n]){ cnt.push_back(n); return; }
  if(n%2 and isP[n-2]){ cnt.push_back(2), cnt.push_back(n-2); return; }
  if(n%2==0){ OddSum(n); return; }
  // 找到三個質數和=n的最大乘積，最大乘績不一定是和n/3距離加總的最小加總，只能窮舉
  // 找到小於等於n/3的質數並窮舉所有乘積可能保留最大的，記得算乘積時先把一個數字轉成long
  int pos=BS(n/3);
  cnt.push_back(prime[pos]),  OddSum(n-prime[pos]);
  long MaxMul=(long)prime[pos]*cnt[0]*cnt[1];
  vector<int>Maxcnt(cnt);
  for(int i=pos-1; i>=0;i--){
    cnt.clear();
    cnt.push_back(prime[i]),  OddSum(n-prime[i]);
    long Mul=(long)prime[i]*cnt[0]*cnt[1];
    if(Mul>MaxMul)  MaxMul=Mul, Maxcnt=cnt;
  }
  cnt=Maxcnt;
  sort(cnt.begin(),cnt.end());
  return;
}
int main(){
  // 建表找質數和做質數判斷的映射表
  prime.push_back(2);
  for(int i=4;i<=1000000;i+=2)
    isP[i]=0;
  for(int i=3; i<1000; i+=2)
    if(isP[i])
      for(int k=2*i,j=i+k; j<=1000000; j+=k)
        isP[j]=0;
  for(int i=3;i<1000000;i+=2)
    if(isP[i])
      prime.push_back(i);
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for(int n;cin>>n and n;){
    cnt.clear();
    PrimeSum(n);
    cout<<cnt.size();
    for(int i=0;i<cnt.size();i++)
      cout<<' '<<cnt[i];
    cout<<endl;
  }
}
/*
27
35
51
57
65
77
87
93
95
*/