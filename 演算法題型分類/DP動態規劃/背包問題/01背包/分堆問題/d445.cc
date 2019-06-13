// 分堆問題=>01背包問題的變形
// 題目問的是組合數，而分組時(A,B)=(B,A)視為相同所以數量只要輸出一半
#include<iostream>
#include<vector>
using namespace std;

int main(){
  for(int N; cin>>N; ){
    int sum=(1+N)*N/2;
    if(sum%2){ cout<<"0"<<endl; continue; }
    int maxN=sum/2;
    vector<long> cnt(maxN+1,0);
    cnt[0]=1;
    for(int i=1;i<=N;i++)
      for(int j=maxN;j>=i;j--)
        cnt[j]+=cnt[j-i];
    cout<<cnt[maxN]/2<<endl;
  }
}