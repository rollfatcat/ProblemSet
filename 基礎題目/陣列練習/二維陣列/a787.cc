// 矩陣翻轉：根據輸入要求『上下翻轉』『左右鏡像翻轉』
#include<iostream>
using namespace std;

int main(){
  string name, act;
  char map[2][24][36];
  int R, C;

  while(cin>>name>>C>>R>>act){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>map[0][i][j];
    bool now=0, nxt=1;
    for(int i=0;i<act.length();i++){
      if(act[i]=='I')
        for(int i=0;i<R;i++)
          for(int j=0;j<C;j++)
            map[nxt][R-1-i][j]=map[now][i][j];
      else
        for(int i=0;i<R;i++)
          for(int j=0;j<C;j++)
            map[nxt][i][C-1-j]=map[now][i][j];
      now=nxt, nxt=1^now;
    }
    cout<<name<<endl;
    for(int i=0;i<R;i++,cout<<endl)
      for(int j=0;j<C;j++)
        cout<<map[now][i][j];
  }
}