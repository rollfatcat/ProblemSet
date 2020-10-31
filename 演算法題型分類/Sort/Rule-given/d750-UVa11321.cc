// 自定義排序規則
#include<iostream>
#include<algorithm>
using namespace std;

int M;
bool compare(int a, int b){
  int aMod=a%M, bMod=b%M;
  if(aMod!=bMod)  return aMod<bMod;
  bool aOdd=a%2,  bOdd=b%2;
  if(aOdd and bOdd) return a>b;
  else if(aOdd==0 and bOdd==0)  return a<b;
  else return aOdd;
}
int main(){
  int N, num[10000];
  while(cin>>N>>M){
    cout<<N<<' '<<M<<endl;
    if(N==0 and M==0)
      break;
    for(int i=0;i<N;i++)
      cin>>num[i];
    sort(num,num+N,compare);
    for(int i=0;i<N;i++)
      cout<<num[i]<<endl;
  }
}