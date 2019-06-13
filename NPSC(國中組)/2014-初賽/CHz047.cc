// 輸出浮點數後三位(補零)

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  cin>>caseT;
  while(caseT--){
    double AB, H, BB, HBP, TB, SF;
    cin>>AB>>H>>BB>>HBP>>TB>>SF;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<(AB*(H+BB+HBP) +TB*(AB+BB+SF+HBP))/ (AB*(AB+BB+SF+HBP) )<<endl;
  }
}