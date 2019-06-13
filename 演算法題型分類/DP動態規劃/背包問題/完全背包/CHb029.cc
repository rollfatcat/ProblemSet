// 湊成某個價格的方法數
#include<iostream>
using namespace std;

int main(){
  int v[5]={2,5,10,20,25};
  int w[1001], W;
  fill(w,w+1001,0);

  w[0]=1;
  for(int i=0;i<5;i++)
    for(int j=v[i];j<=1000;j++)
      w[j]+=w[j-v[i]];
  while(cin>>W)
    cout<<w[W]<<endl;
}