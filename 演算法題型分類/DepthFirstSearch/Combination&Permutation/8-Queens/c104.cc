// 8 Queens 簡單變形題(需要偷跑)
#include<iostream>
using namespace std;

int cnt=0;
int pos_x[8], map[92][8];
bool Lslash[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool Rslash[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool col[8]={1,1,1,1,1,1,1,1};
bool *ls=&Lslash[0];  // /  範圍變化：x+y =  0 ~ 16
bool *rs=&Rslash[8];  // \  範圍變化：x-y = -8 ~  8
void DFS(int y){
  if(y==8){
    for(int i=0;i<8;i++)
      map[cnt][i]=pos_x[i];
    cnt++;
    return;
  }
  for(int i=0;i<8;i++)
    if(col[i] and ls[i+y] and rs[i-y]){
      pos_x[y]=i;
      ls[i+y]=rs[i-y]=col[i]=false;
      DFS(y+1);
      ls[i+y]=rs[i-y]=col[i]=true;
    }
}
int main(){
  int T;
  // 先產生八皇后的92種答案
  DFS(0);
  cin>>T;
  while(T--){
    int val[8][8];
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
        cin>>val[i][j];
    int total=0;
    for(int t=0, tmp=0; t<cnt;t++, tmp=0){
      for(int i=0;i<8;i++)
        tmp+=(val[i][map[t][i]]);
      if(total<tmp)
        total=tmp;
    }
    printf("%5d\n",total);
  }
}