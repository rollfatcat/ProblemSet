// 值得練習
// 練習二元樹和自己推理規則的模擬題
// 陣列位置和二元樹路徑的關係
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int R, C;

  while(cin>>R>>C and R){
    if(R==1){
      if(C==1)  cout<<"0/1"<<endl;
      else      cout<<"1/0"<<endl;
      continue;
    }
    R--, C--;
    vector<bool>path(R-1,0);
    for(int i=0;C>0;i++)
      path[i]=C%2,  C/=2;
    int lx=0, ly=1, rx=1, ry=0, mx=1, my=1;
    for(int i=R-2; i>=0;i--){
      if(path[i]==0)
        rx=mx,  ry=my;
      else
        lx=mx,  ly=my;
      mx=lx+rx, my=ly+ry;
    }
    cout<<mx<<'/'<<my<<endl;
  }
}