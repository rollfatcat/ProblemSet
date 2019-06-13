#include<iostream>
#include<cmath>
using namespace std;
#define MaxNum 100

int N, val[MaxNum], len[MaxNum];
int LongestIncreasingSequence(){
  fill(len,len+N,1);
  for (int i=0; i<N; i++)
    // 找出 val[i] 後面能接上哪些數字，若是可以接，長度就增加。
    for(int j=i+1; j<N; j++)
      if(val[i]<val[j])
        len[j]=max( len[j], len[i]+1);
  int out=len[0];
  for(int i=1;i<N;i++)
    out=max(out,len[i]);
  return out;
}
int main(){
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>val[i];
  cout<<LongestIncreasingSequence()<<endl;
}