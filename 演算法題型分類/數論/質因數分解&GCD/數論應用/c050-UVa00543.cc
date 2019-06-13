// 驗證 Goldbach's Conjecture：任何一個比4大的偶數一定能夠找到2個奇數的質數使其和相等
#include<iostream>
#include<vector>
using namespace std;

bool isP[1000000]={0};
int main(){
  vector<int>prime;
  for(int i=2;i<1000;i++)
    if(!isP[i])
      for(int j=(i<<1);j<1000000;j+=i)
        isP[j]=true;
  for(int i=2;i<1000000;i++)
    if(!isP[i])
      prime.push_back(i);
  for(int n, i; cin>>n and n; ){
    for(i=1; prime[i]<=(n>>1) and isP[n-prime[i]];i++);
    if(prime[i]>(n>>1)) cout<<"Goldbach's conjecture is wrong."<<endl;
    else  cout<<n<<" = "<<prime[i]<<" + "<<n-prime[i]<<endl;
  }
}