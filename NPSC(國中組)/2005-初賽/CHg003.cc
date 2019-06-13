// 實質是算LCM(最小公倍數)
#include<iostream>
using namespace std;

int GCD(int a, int b){ return(a%b)?GCD(b,a%b):b; }
int main(){
  int caseNum, a, b;

  cin>>caseNum;
  while(caseNum--)
    cin>>a>>b,
    cout<<(a*b/((a>b)?GCD(a,b):GCD(b,a)))<<endl;
}