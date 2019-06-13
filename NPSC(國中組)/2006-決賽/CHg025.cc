// 暴力法計算所有組合的距離取大值, 注意更新方向
#include<iostream>
using namespace std;

int main(){
  int n, x[3000], y[3000];

  while(cin>>n and n){
    for(int i=0;i<n;i++)
      cin>>x[i]>>y[i];
    int maxDis=0, a=-1, b=-1;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
        int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        if(dis>maxDis)
          a=i, b=j, maxDis=dis;
      }
    cout<<a<<' '<<b<<endl;
  }
}