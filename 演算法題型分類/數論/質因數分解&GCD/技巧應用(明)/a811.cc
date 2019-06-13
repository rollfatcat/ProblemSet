// 題目定義的『最可能』的等差 => 找出所有等差的最大公因數(?)
#include<iostream>
#include<algorithm>
using namespace std;

long GCD(long a,long b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T,N;
  long num[10000];
  for(cin>>T;T--;){
    cin>>N;
    for(int i=0;i<N;i++)
      cin>>num[i];
    sort(num,num+N);
    for(int i=N-1;i>0;i--)
      num[i]-=num[i-1];
    long ans=num[1];
    for(int i=2;i<N;i++)
      ans=GCD(ans,num[i]);
    cout<<ans<<endl;
  }
}