// 簡單數論：總和公式+GCD
#include<iostream>
using namespace std;

int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ss="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int a,b,c; cin>>a>>b>>c;){
    int LCM=a*b/GCD(a,b);
    int nA=c/a, nB=c/b, nL=c/LCM;
    int sum=a*(nA+1)*nA/2+b*(nB+1)*nB/2-LCM*(nL+1)*nL/2;
    cout<<ss[(sum-1)%26]<<endl;
  }
}