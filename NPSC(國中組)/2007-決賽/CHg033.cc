// 做兩次的質因數分解, 注意第一次找到的因數總和可能超過1000000
// 但不代表這個總和拿去質因數分解後的因數總和不會回到原先的數字,以下兩組即是：
// 947835 1125765
// 998104 1043096
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int num[1000001]={0};
vector<int> prime;
long long int GetPair(int n){
  if(n<=1000000 and num[n]>1)
    return num[n];
  int p, x=n;
  long long int store=1;
  for(int i=0;i<prime.size() and prime[i]<=sqrt(x) and x>1;i++){
    for(p=0; x%prime[i]==0; x/=prime[i],p++);
    if(p>0) store*=(pow((double)prime[i],p+1)-1)/(prime[i]-1);
  }
  if(x>1) store*=(x+1);
  if(n<=1000000)  num[n]=store-n;
  return store-n;
}
int main(){
  for(int i=2;i<1000;i++)
    if(num[i]==0){
      prime.push_back(i);
      for(int j=2; i*j<=1000000; j++)
        num[i*j]=1;
    }
  int n;
  while(scanf("%d",&n) and n)
    if(num[n]==0) printf("0\n");
    else{
      int pairN=GetPair(n);
      if(n==pairN)  printf("=%d\n",n);
      else if(pairN<=1000000 and n==GetPair(pairN))  printf("%d\n",pairN);
      else printf("0\n");
    }
}