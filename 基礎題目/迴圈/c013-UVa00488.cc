// 簡單迴圈控制, 注意換行的條件
#include<iostream>
using namespace std;

int main(){
  int T, A, F;

  cin>>T;
  while(T--){
    cin>>A>>F;
    while(F--){
      for(int i=1;i<=A;i++,cout<<endl)
        for(int j=1;j<=i;j++)
          cout<<i;
      for(int i=A-1;i>0;i--,cout<<endl)
        for(int j=1;j<=i;j++)
          cout<<i;
      if(T or F)
      cout<<endl;
    }
  }
}