// 同c121的大數加法, 但是目標是前20000個Fib
// 所以時間吃得很緊一定要調整base(不能以10為單位), 這題的base=1e9不會出錯
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 20001

vector< vector<int> >num(MaxN);
int main(){
  int base=100000000;

  num[0].push_back(0);
  num[1].push_back(1);
  for(int idx=2;idx<=20000;idx++){
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
    cout<<num[n].back();
    for(int i=num[n].size()-2;i>=0;i--)
      printf("%08d",num[n][i]);
    printf("\n");
  }
}