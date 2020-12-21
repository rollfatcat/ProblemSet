#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 8001

int main(){
  int cnt[8]={1,13,33,43,139,169,1309,2597};
  long long int map[MaxN];
  memset(map,0,sizeof(map));
  map[0]=1;
  for(int i=0;i<8;i++)
    for(int j=cnt[i];j<=8000;j++)
      map[j]+=map[j-cnt[i]];
  int n;
  while(cin>>n)
    cout<<map[n]<<endl;
}