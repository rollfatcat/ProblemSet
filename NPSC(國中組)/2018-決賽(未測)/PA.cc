// 輸出半小時後的時間格式，需要處理時間的溢位問題

#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, H, M;
  cin>>caseT;
  while(caseT--){
    cin>>H>>M;
    M+=30;
    if(M>=60) M-=60, H++;
    if(H>=24) H-=24;
    cout<<H<<' '<<M<<endl;
  }
}