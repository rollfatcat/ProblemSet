// 單位數的大數乘除法
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N;
  cin>>N;

  vector<int>num;
  num.push_back(4);
  for(int p=1;p<N;p++){
    int carry=0;
    for(int i=0;i<num.size();i++)
      num[i]=(num[i]<<2)+carry,
      carry=num[i]/10,
      num[i]%=10;
    for(; carry; carry/=10)
      num.push_back(carry%10);
  }
  num[0]-=1; //個位數不可能是0
  int now=num.back(), i=num.size()-2;
  if(now<3) now=10*now+num[i--];
  for(cout<<(now/3), now%=3; i>=0; i--)
    now=10*now+num[i], cout<<(now/3), now%=3;
  cout<<endl;
}