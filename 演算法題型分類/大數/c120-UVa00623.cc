// 1000! 用base=1e6來加速
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 1001

vector< vector<int> >num(MaxN);
int main(){
  num[0].push_back(1);
  num[1].push_back(1);
  int base=1000000;
  for(int idx=2;idx<=1000;idx++){
    int carry=0;
    for(int i=0;i<num[idx-1].size();i++)
      num[idx].push_back(num[idx-1][i]*idx+carry),  carry=num[idx][i]/base,  num[idx][i]=num[idx][i]%base;
    if(carry) num[idx].push_back(carry);
  }
  for(int n;cin>>n;){
    cout<<n<<'!'<<endl;
    printf("%d",num[n][num[n].size()-1]);
    for(int i=num[n].size()-2;i>=0;i--)
      printf("%06d",num[n][i]);
    printf("\n");
  }
}