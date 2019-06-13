// d709的加強版
// 在建表過程和質數個數判斷中選擇 0.3s/19.5MB
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool NP[20000001]={0};
int main(){
  NP[1]=1;
  vector<int> prime, p2;
  // 建質數表
  int bound=sqrt(2147483647);
  prime.push_back(2), p2.push_back(4);
  for(int i=4;i<=20000000;i+=2)  NP[i]=true;
  for(int i=3;i<=bound;i+=2)
    if(!NP[i]){
      prime.push_back(i), p2.push_back(i*i);
      for(int k=(i<<1), j=k+i; j<=20000000; j+=k)
        NP[j]=true;
    }
  p2.push_back(2147483647);// 塞一個保底的值,且2147483647是質數,額外判斷即可
  //
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for(int n; cin>>n and n;)
    if(n<=20000000) cout<<NP[n]<<endl;
    else{
      if(n==2147483647){ cout<<0<<endl; continue; }
      int idx=0;
      for( ; p2[idx]<=n and n%prime[idx]; idx++);
      cout<<((p2[idx]>n)?0:1)<<endl;
    }
}