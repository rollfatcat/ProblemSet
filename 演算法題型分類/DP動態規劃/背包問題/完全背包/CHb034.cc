// 沒有50000, 所以金額>=10000要額外計算
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int cnt[10]={0,1,2,3,4,1,2,3,4,5};
  for(int total;cin>>total;){
    int num=total/10000;
    for(total=total%10000;total>0;total/=10)
      num+=cnt[total%10];
    cout<<num<<endl;
  }
}