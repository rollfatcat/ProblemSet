// 題目同 中女中APSC CHg033題目, 請嘗試以下測資(題目不保證答案在1000000範圍內)
// 947835 1125765
// 998104 1043096
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long num[1000001]={0};
vector<int> prime;
long GetPair(int n){
  if(n<=1000000 and num[n]>1) return num[n];
  int p, x=n;
  long store=1;
  for(int i=0;i<prime.size() and x>1 and prime[i]*prime[i]<=x;i++){
    for(p=0; x%prime[i]==0; x/=prime[i],p++);
    if(p>0) store*=(pow((long)prime[i],p+1)-1)/(prime[i]-1);
  }
  if(x>1) store*=(x+1);
  // 題目問的範圍只到1000000
  if(n<=1000000)  num[n]=store-n;
  return store-n;
}
int main(){
  for(int i=2;i<46340;i++) // 保證找到int內的全部需要判斷的質數
    if(num[i]==0){
      prime.push_back(i);
      for(int j=(i<<1); j<=1000000; j+=i)
        num[j]=1;
    }
  int n;
  while(scanf("%d",&n) and n)
    if(num[n]==0) printf("0\n");
    else{
      int pairN=GetPair(n);
      if(n==pairN)  printf("=%d\n",n);
      else if(n==GetPair(pairN))  printf("%d\n",pairN);
      else printf("0\n");
    }
}