// 前5000個Fib ,大數加法
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 5001

vector< vector<int> >num(MaxN);
int main(){
  int base=100000000;

  num[0].push_back(0);
  num[1].push_back(1);
  for(int idx=2;idx<=5000;idx++){
    int carry=0;
    for(int i=0;i<num[idx-2].size();i++)
      num[idx].push_back(num[idx-1][i]+num[idx-2][i]+carry),
      carry=num[idx][i]/base,
      num[idx][i]=num[idx][i]%base;
    for(int i=num[idx-2].size();i<num[idx-1].size();i++)
      num[idx].push_back(num[idx-1][i]+carry),
      carry=num[idx][i]/base,
      num[idx][i]=num[idx][i]%base;
    if(carry>0) num[idx].push_back(carry);
  }

  for(int n;cin>>n;){
    cout<<"The Fibonacci number for "<<n<<" is "<<num[n][num[n].size()-1];
    for(int i=num[n].size()-2;i>=0;i--)
      printf("%08d",num[n][i]);
    printf("\n");
  }
}