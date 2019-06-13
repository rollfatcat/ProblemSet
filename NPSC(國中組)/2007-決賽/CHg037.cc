#include<iostream>
#include<cmath>
using namespace std;

int GCD(int a, int b){ return(a%b)?GCD(b,a%b):b; }
struct Node{ int x, y; }p1, p2, v;
int main(){
  int caseNum;

  cin>>caseNum;
  while(caseNum--){
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    v.x=abs(p2.x-p1.x),  v.y=abs(p2.y-p1.y);
    if(v.x==0)      cout<<(1+v.y)<<endl;
    else if(v.y==0) cout<<(1+v.x)<<endl;
    else            cout<<((v.x>v.y)?GCD(v.x, v.y):GCD(v.y, v.x))+1<<endl;
  }
}