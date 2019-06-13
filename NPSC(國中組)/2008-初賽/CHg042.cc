// 不用無限背包, 因為面值都是倍數關係
#include<iostream>
using namespace std;

int main(){
  int caseNum, n ,cnt;
  int num[4]={1,3,9,27};

  cin>>caseNum;
  while(caseNum--){
    cin>>n;
    cnt=0;
    for(int i=3;i>=0;i--)
      cnt+=(n/num[i]),  n=n%num[i];
    cout<<cnt<<endl;
  }
}