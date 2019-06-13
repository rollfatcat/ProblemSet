// 做法同完成 c050-uva00543，只是這次要找出所有組合解
#include<iostream>
#include<vector>
using namespace std;

vector<int>isP(1<<15,1);
int main(){
  vector<int>prime;
  for(int i=2;i<=181;i++)
    if(isP[i])
      for(int j=(i<<1);j<(1<<15);j+=i)
        isP[j]=0;
  for(int i=2;i<(1<<15);i++)
    if(isP[i])
      prime.push_back(i);

  for(int n, cnt; cin>>n and n; ){
    cnt=0;
    for(int i=0; prime[i]<=(n>>1);i++)
      if(isP[n-prime[i]])
        cnt++;
    cout<<cnt<<endl;
  }
}