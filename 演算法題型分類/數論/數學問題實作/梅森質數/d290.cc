// 輸出5th完全數(因數和=本身數值), 建議學生找到6th和7th完全數可以用longlongint處理
// 數論題, 梅森完全數性質(參考wiki)濾除可能的答案
// 梅森完全數=> n is prime, and (1<<(n-1))-1 is also prime, then [(1<<(n-1))-1]*[(1<<n-1)-1] is possibly a Perfect Number.
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main(){
  // 產生8128以內的判斷用質數先寫一份在陣列再複製一份到vector, prime<sqrt(8128)
  long primeN[24]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89};
  vector<long>prime(primeN,primeN+24);

  for(int primeIdx=4; true; primeIdx++){
    // 梅森完全數
    long N=((long)1<<(prime[primeIdx]-1))*((1<<prime[primeIdx])-1),  bound=sqrt(N);
    // 梅森完全數內的有效判斷質數, 從上次最後的質數開始往下找
    // 7th梅森完全數的質數範圍是370723( 31579th prime )
    for(long num=prime.back()+2, i; num<=bound; num+=2){
      for(i=0;i<prime.size() and num%prime[i]; i++);
      if(i==prime.size()) prime.push_back(num);
    }
    // 判斷該梅森完全數是不是質數
    long n=N, cnt=1, p;
    for(int i=0;i<prime.size() and prime[i]*prime[i]<=n and n>1;i++)
      if(n%prime[i]==0){
        for(p=0;n%prime[i]==0 and n>1;n/=prime[i], p++);
        cnt*=((pow(prime[i],p+1)-1)/(prime[i]-1));
      }
    if(n>1) cnt*=(n+1);
    if(cnt==(N<<1)){  cout<<N<<endl; }
  }
}