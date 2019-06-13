// 無限背包問題
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int caseNum, N, S, base;
  long long int map[10001];

  cin>>caseNum;
  while(caseNum--){
    memset(map,0,sizeof(map));
    map[0]=1;
    cin>>N>>S;
    for(int i=0;i<N;i++){
       cin>>base;
       for(int j=base;j<=S;j++)
        map[j]+=map[j-base];
    }
    cout<<map[S]<<endl;
  }
}