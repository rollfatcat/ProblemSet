// 測資範圍：M,N ≤ 1e9
// 注意：可能是中女中的編譯器太舊，所以必須使用longlong(long會被當int而已)

#include<iostream>
#include<cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  long long N, M, cnt, B;
  cin>>caseT;
  while(caseT--){
    cin>>N>>M;
    cnt=M*(M+1)/2;
    B=M/N;
    cnt+=N*B*(B-1)/2+(M%N)*B;
    cout<<cnt<<'\n';
  }
}