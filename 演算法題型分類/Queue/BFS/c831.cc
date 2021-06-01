// 偽BFS
// 一開始以為是雙向BFS，但是路線上沒有障礙物，不需要這麼麻煩
#include<iostream>
using namespace std;

int main(){
  long lx,ly,rx,ry,x1,y1,x2,y2;
  cin>>lx>>ly>>rx>>ry>>x1>>y1>>x2>>y2;
  if(x1>x2) x1^=x2^=x1^=x2;
  if(y1>y2) y1^=y2^=y1^=y2;
  cout<<min(abs(x2-x1),abs(x1-lx+rx-x2))+min(abs(y2-y1),abs(y1-ly+ry-y2))<<endl;
}
