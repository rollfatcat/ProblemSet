// 簡單尋找陣列中最小的數
#include<iostream>
using namespace std;
#define TypeNum 42

int main(){
  int N, M, a;
  int num[TypeNum];
  while(cin>>N and N){
    fill(num,num+TypeNum,0);
    while(N--){
      cin>>M;
      while(M--){
        cin>>a; num[a]++;
      }
    }
    int ans=num[1];
    for(int i=2;i<TypeNum;i++)
      if(ans>num[i])
        ans=num[i];
    cout<<ans<<endl;
  }
}