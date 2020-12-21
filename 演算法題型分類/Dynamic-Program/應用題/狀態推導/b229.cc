// 題目和 c731 相同
/* 往上走一步則下一步有 3 個選擇：左/上/右 => F(3)=F(2)+2*f(2)
 * 往左走一步則下一步有 2 個選擇：上/右    => f(3)=F(2)+f(2)
 * 往右走一步則下一步有 2 個選擇：左/上
 * 注意：最大值需要用到unsigned long long int
 */
#include<iostream>
using namespace std;
#define MaxN 51

unsigned long long int up[MaxN], side[MaxN];
unsigned long long int GoUp(int step);
unsigned long long int GoSide(int step);

int main(){
  fill(up,up+MaxN,0);
  fill(side,side+MaxN,0);
  up[1]=3,  side[1]=2;

  int N;
  while(cin>>N)
    cout<<GoUp(N)<<endl;
}

unsigned long long int GoUp(int step){
  if(up[step]==0)
    up[step]=GoUp(step-1)+2*GoSide(step-1);
  return up[step];
}
unsigned long long int GoSide(int step){
  if(side[step]==0)
    side[step]=GoUp(step-1)+GoSide(step-1);
  return side[step];
}