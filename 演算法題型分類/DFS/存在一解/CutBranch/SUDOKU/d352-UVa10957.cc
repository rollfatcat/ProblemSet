// 暴力法填格子+簡單剪枝, 方法數達2個以上時就可以不用繼續做DFS
#include<iostream>
#include<cstring>
using namespace std;

bool Illegal;
int sudo[9][9], cnt;
bool row[9][10], col[9][10], maze[3][3][10];
void DoInput(int r, int c, int num){
  sudo[r][c]=num;
  if(num==0)  return;
  if(row[r][num]==0) row[r][num]=1;
  else  Illegal=true;
  if(col[c][num]==0) col[c][num]=1;
  else  Illegal=true;
  if(maze[r/3][c/3][num]==0) maze[r/3][c/3][num]=1;
  else  Illegal=true;
}
void DFS(int r,int c){
  if(c==9) r++, c=0;
  if(r==9){ cnt++;  return; }
  if(sudo[r][c]==0){ // 可以填的格子
    for(int i=1;i<=9;i++)
      if(row[r][i]==0 and col[c][i]==0 and maze[r/3][c/3][i]==0){
        sudo[r][c]=i;
        row[r][i]=col[c][i]=maze[r/3][c/3][i]=1;
        DFS(r,c+1);
        if(cnt>1)  return;
        row[r][i]=col[c][i]=maze[r/3][c/3][i]=0;
      }
    sudo[r][c]=0;
  }
  else{ //已經有數字不用填,換到下一格
    DFS(r,c+1);
    if(cnt>1)  return;
  }
}
int main(){
  int x;
  string msg[3]={"Impossible.\n","Unique.\n","Ambiguous.\n"};

  for(int caseNum=1; cin>>x; caseNum++){
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(maze,0,sizeof(maze));
    Illegal=cnt=0;
    DoInput(0,0,x);
    for(int i=1;i<9;i++)
      cin>>x, DoInput(0,i,x);
    for(int i=1;i<9;i++)
      for(int j=0;j<9;j++)
        cin>>x, DoInput(i,j,x);
    if(Illegal==false) // 輸入要合法,才有可能暴力法去嘗試,不然無意義
      DFS(0,0), cout<<"Case "<<caseNum<<": "<<msg[cnt];
    else
      cout<<"Case "<<caseNum<<": "<<"Illegal.\n";
  }
}