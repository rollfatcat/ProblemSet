// 一定不是暴力法去算全部的頭和尾的組合...正確作法請參照v1
#include<iostream>
using namespace std;
#define MaxNum 100

int N, val[MaxNum], sum[MaxNum+1];
int main(){
  cin>>N;
  sum[0]=0;
  for(int i=0;i<N;i++)
    cin>>val[i], sum[i+1]=sum[i]+val[i];
  int bonus=0;
  for(int st=0;st<N;st++)
    for(int ed=st+1;ed<=N;ed++){
      int tmp=sum[ed]-sum[st];
      if(bonus<tmp)
        bonus=tmp;
    }
  cout<<bonus<<endl;
}