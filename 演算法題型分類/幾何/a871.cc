// 數論：二維平面上求多邊形的面積
// 鞋帶公式(不需要管順逆時針順序，可直接計算答案)
// 答案出處：morris821028
#include<iostream>
#include<cmath>
using namespace std;

struct nn{ double x, y; }node[10];
int main(){
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);

  for(int n; cin>>n;){
    for(int i=0;i<n;i++)
      cin>>node[i].x>>node[i].y;
    double area=0.0;
    for(int i=0;i<n-1;i++)
      area+=(node[i].x*node[i+1].y)-(node[i+1].x*node[i].y);
    area+=(node[n-1].x*node[0].y)-(node[0].x*node[n-1].y);
    printf("%.2lf\n",abs(area)/2);
  }
}