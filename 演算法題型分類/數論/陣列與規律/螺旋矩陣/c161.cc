// 數論題：觀察規律 => 如果不在最外層就往內找，在外層時依照順時針判斷
// 螺旋矩陣的遞迴解法：https://blog.csdn.net/Orion_Rigel/article/details/53012154
#include<iostream>
using namespace std;

int Rotate(int n,int x,int y){
  if(x==1) return y;
  if(y==n) return (n-1)+x;
  if(x==n) return 2*(n-1)+(n-y+1);
  if(y==1) return 3*(n-1)+(n-x+1);
  return 4*(n-1)+Rotate(n-2,x-1,y-1);
}
int main(){
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for(int n,x,y; cin>>n>>x>>y;)
    cout<<Rotate(n,x,y)<<endl;
}