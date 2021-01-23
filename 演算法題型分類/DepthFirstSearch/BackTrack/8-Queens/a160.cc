// 8 Queens
#include<iostream>
using namespace std;
#define MaxN 11

int N, cnt;
int x[MaxN];
bool Lslash[2*MaxN], Rslash[2*MaxN], col[MaxN];
bool *ls=&Lslash[0];  // /  範圍變化：x+y=0~2(N-1)
bool *rs=&Rslash[10]; // \  範圍變化：x-y=-(N-1)~(N-1)

void DFS(int y){
  if(y==N){
    cnt++;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++)
        if(j==x[i])
          cout<<'Q';
        else
          cout<<'x';
      cout<<endl;
    }
    cout<<endl;
    return;
  }
  for(int i=0;i<N;i++)
    if(col[i] and ls[i+y] and rs[i-y]){
      x[y]=i;
      ls[i+y]=rs[i-y]=col[i]=false;
      DFS(y+1);
      ls[i+y]=rs[i-y]=col[i]=true;
    }
}
int main(){
  while(cin>>N and N){
    fill(col,col+N,1);
    fill(Lslash,Lslash+2*MaxN,1);
    fill(Rslash,Rslash+2*MaxN,1);
    cnt=0;
    DFS(0);
    cout<<cnt<<endl;
  }
}
