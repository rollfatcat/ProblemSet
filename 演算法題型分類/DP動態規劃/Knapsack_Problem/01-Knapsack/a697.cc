// 有限背包的『方法數』問題
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100

int main(){
  int n, sum, bound;

  cin>>n>>sum;
  int map[sum+1];
  memset(map,0,sizeof(map));
  map[0]=1;
  for(int i=0;i<n;i++){
    cin>>bound;
    for(int j=sum;j>0;j--){
      for(int k=1;k<=bound and k<=j;k++)
        map[j]=(map[j]+map[j-k])%1000007;
    }
    for(int j=0;j<=sum;j++)
      cout<<map[j]<<' ';
    cout<<endl;
  }
  //cout<<map[sum]<<endl;
}