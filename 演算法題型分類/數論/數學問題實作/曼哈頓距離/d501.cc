// 國中數學：給N個一維座標點，求絕對差值的總和最小化
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int num[1000000], n;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>n){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    if(n%2) cout<<"A="<<num[n>>1]<<endl;
    else{
      n>>=1;
      cout<<"A="<<num[n-1];
      for(int i=num[n-1]+1, j=num[n];i<=j;i++)
        cout<<"、"<<i;
      cout<<endl;
    }
  }
}