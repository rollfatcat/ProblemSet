#include<iostream>
using namespace std;

int R, C, M;
int result[10][10];
// 上下翻轉的逆向=自己
void Reverse(){
  for(int i=0;i<R/2;i++)
    for(int j=0;j<C;j++){
      int tmp=result[i][j];
      result[i][j]=result[R-1-i][j];
      result[R-1-i][j]=tmp;
    }
}
// 90度順向轉動的逆向=先橫向翻轉再做Transport
void Translate(){
  int temp[10][10],tmp;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      temp[C-1-j][i]=result[i][j];
  tmp=C;
  C=R;
  R=tmp;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      result[i][j]=temp[i][j];
}

int main(){
  bool act[10];
  while(cin>>R>>C>>M){
    //處理輸入
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>result[i][j];
    for(int i=0;i<M;i++)
      cin>>act[i];
    //根據輸入的順序作逆向操作
    for(int i=M-1;i>=0;i--)
      if(act[i])
        Reverse();
      else
        Translate();
    //輸出格式
    cout<<R<<' '<<C<<endl;
    for(int i=0;i<R;i++){
      cout<<result[i][0];
      for(int j=1;j<C;j++)
        cout<<' '<<result[i][j];
      cout<<endl;
    }
  }
}