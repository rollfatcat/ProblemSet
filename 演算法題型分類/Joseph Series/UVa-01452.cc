// n極大, 只能做DP解
#include<iostream>
using namespace std;

int main(){
  int num[3], n, k, caseNum;

  for(cin>>caseNum; caseNum--; ){
    cin>>n>>k;
    // 2nd Turn
    num[0]=k%2;
    num[1]=1-num[0];
    // 3rd Turn
    num[0]=(num[0]+k)%3;
    num[1]=(num[1]+k)%3;
    num[2]=3-num[1]-num[0];
    for(int t=4;t<=n;t++)
      for(int i=0;i<3;i++)
        num[i]=(num[i]+k)%t;
    cout<<(num[2]+1)<<' '<<(num[1]+1)<<' '<<(num[0]+1)<<endl;
  }

}