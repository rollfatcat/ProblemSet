#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 40000

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, n, num[MaxN];

  cin>>T;
  while(T--){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    n=(n>>1)-!(n&1);
    cout<<num[n]<<endl;
  }
}