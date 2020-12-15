// 暴力法填數獨，與d263-UVa00989相同
#include<iostream>
#include<cstring>
using namespace std;

int bound_n;
bool NoAns, LegalInput;
int sudo[9][9], n;
bool row[9][10], col[9][10], maze[3][3][10];
void DFS(int r,int c){
  if(c==bound_n) r++, c=0;
  if(r==bound_n){ NoAns=false;  return; }
  if(sudo[r][c]==0){ // 可以填的格子
    for(int i=1;i<=bound_n;i++)
      if(row[r][i]==0 and col[c][i]==0 and maze[r/n][c/n][i]==0){
        sudo[r][c]=i;
        row[r][i]=col[c][i]=maze[r/n][c/n][i]=1;
        DFS(r,c+1);
        if(NoAns==false)  return;
        row[r][i]=col[c][i]=maze[r/n][c/n][i]=0;
      }
    sudo[r][c]=0;
  }
  else{ //已經有數字不用填,換到下一格
    DFS(r,c+1);
    if(NoAns==false)  return;
  }
}
int main(){
  while(cin>>n){
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(maze,0,sizeof(maze));
    bound_n=n*n;
    LegalInput=NoAns=true;
    for(int i=0;i<bound_n;i++)
      for(int j=0;j<bound_n;j++){
        cin>>sudo[i][j];
        if(sudo[i][j]){
          if(sudo[i][j]>bound_n){  LegalInput=false; continue; }
          if(row[i][ sudo[i][j] ]==0) row[i][ sudo[i][j] ]=1;
          else  LegalInput=false;
          if(col[j][ sudo[i][j] ]==0) col[j][ sudo[i][j] ]=1;
          else  LegalInput=false;
          if(maze[i/n][j/n][ sudo[i][j] ]==0) maze[i/n][j/n][ sudo[i][j] ]=1;
          else  LegalInput=false;
        }
      }
    if(LegalInput) // 輸入要合法,才有可能暴力法去嘗試,不然無意義
      DFS(0,0);
    if(NoAns) cout<<"NO SOLUTION\n";
    else
      for(int i=0;i<bound_n;i++){
        cout<<sudo[i][0];
        for(int j=1;j<bound_n;j++)
          cout<<' '<<sudo[i][j];
        cout<<endl;
      }
  }
}