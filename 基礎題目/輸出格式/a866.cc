// 眾數的概念
// cout精確度/寬度控制(不可和printf()/scanf()混用)
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int cnt[6]={};
  for(int n; cin>>n and n>0;)
    cnt[n]++;
  int sum=0, num=0;
  for(int i=5; i>0; sum+=i*cnt[i] ,num+=cnt[i--]){
    cout<<i<<" ("<<setw(2)<<cnt[i]<<") |";
    for(int j=0;j<cnt[i];j++)
      cout<<"=";
    cout<<endl;
  }
  cout<<"Average rating: "<<setiosflags(ios::fixed)<<setprecision(4)<<((double)sum/num)<<endl;
}
