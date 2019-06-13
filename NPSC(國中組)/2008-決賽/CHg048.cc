// 相除比較,精確度會因為小數點誤差, 改為相乘比較即可
#include<iostream>
using namespace std;

int GCD(int a, int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  int caseNum, p1[2], p2[2], p3[2];
  int v0[2], v1[2];

  cin>>caseNum;
  while(caseNum--){
    cin>>p1[0]>>p1[1]>>p2[0]>>p2[1]>>p3[0]>>p3[1];
    v0[0]=p2[0]-p1[0], v0[1]=p2[1]-p1[1];
    v1[0]=p3[0]-p1[0], v1[1]=p3[1]-p1[1];
    if(v0[0]==0 and v1[0]==0) cout<<"NO"<<endl;
    else if(v0[1]*v1[0]==v1[1]*v0[0]) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
}