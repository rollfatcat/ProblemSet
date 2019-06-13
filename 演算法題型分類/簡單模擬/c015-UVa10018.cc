// 4294967295代表的意思是 unsigned int 可處理
// ZeroJudge的測資測試不出 unsigned int, 但UVA有要注意
// 停止條件是目前的數字呈現『回文』狀態

#include<iostream>
using namespace std;

unsigned int inverseNum(unsigned int x){
  for(int n=0; true; x/=10){
    if(x==0)  return n;
    n=10*n+x%10;
  }
}
bool checkNum(unsigned int x){
  int n[10], len=0;
  for(;x;x/=10)
    n[len++]=x%10;
  int idx=0;
  while(idx<(len/2) and n[idx]==n[len-1-idx])
    idx++;
  return idx==(len/2);
}
int main(){
  int N, cnt;
  unsigned int x;

  cin>>N;
  while(N--){
    cin>>x;
    cnt=0;
    do{
      cnt++;
      x=x+inverseNum(x);
    }while( !checkNum(x) );
    cout<<cnt<<' '<<x<<endl;
  }
}