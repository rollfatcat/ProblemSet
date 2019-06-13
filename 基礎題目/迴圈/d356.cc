// double和陣列的練習
#include<iostream>
using namespace std;

int main(){
  int K[16];
  double sum=0.0;
  for(int i=1,idx=1; idx<=15; i++){
    sum+=(1.0/i);
    if(sum>idx)
      K[idx++]=i;
  }
  for(int n; cin>>n;)
    cout<<K[n]<<endl;
}