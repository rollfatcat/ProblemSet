// 證明和說明請參照wiki：擴展歐幾里得算法
// 貝祖等式：ax+by=gcd(a,b)
#include<iostream>
using namespace std;
// 遞迴版本的寫法
int gcdEx(int a,int b,int *x,int *y){
  if(b==0){ *x=1,*y=0;  return a; }
  int r=gcdEx(b, a%b, x, y); // r=GCD(a, b)=GCD(b, a%b)
  int t=*x;
  *x=*y;
  *y=t-a/b*(*y);
  return r;
}
// x是a的乘法反元素
int inverseA(int a,int b){
  int x, y, r=gcdEx(a,b,&x,&y);
  return (x<0)?(x+b):x;
}
int main(){
  // a÷b ≡ a×inv(b) ≡ x (mod m)
  for(int a,m; cin>>a>>m; )
    cout<<inverseA(a,m)<<endl;
}

