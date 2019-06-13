#include<iostream>
using namespace std;

int N, maxCnt, cnt;
bool map[4][4];   //'X'=1, '.'=0
int canPut[4][4]; // 代表這一格被幾個城堡給佔著(最多兩個, Row+Col)避免回朔時被直接設定導致錯誤
void DFS(int x, int y){
  if(x==N){
    if(maxCnt<cnt)
      maxCnt=cnt;
    return;
  }
  if(canPut[x][y]==0){ //只有當這格完全沒被擋到才能放
    cnt++;
    for(int i=x;i<N and !map[i][y];i++)  canPut[i][y]++;  //往下
    for(int i=x-1;i>=0 and !map[i][y];i--) canPut[i][y]++;//往上
    for(int i=y;i<N and !map[x][i];i++)  canPut[x][i]++;  //往右
    for(int i=y-1;i>=0 and !map[x][i];i--) canPut[x][i]++;//往左
    if(y==N-1)  DFS(x+1,0);
    else  DFS(x, y+1);
    for(int i=x;i<N and !map[i][y];i++)  canPut[i][y]--;
    for(int i=x-1;i>=0 and !map[i][y];i--) canPut[i][y]--;
    for(int i=y;i<N and !map[x][i];i++)  canPut[x][i]--;
    for(int i=y-1;i>=0 and !map[x][i];i--) canPut[x][i]--;
    cnt--;
  }
  if(y==N-1)  DFS(x+1,0);
  else  DFS(x, y+1);
}

int main(){
  char c;
  while(cin>>N and N){
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        cin>>c, map[i][j]=canPut[i][j]=(c=='X');
    maxCnt=cnt=0;
    DFS(0,0);
    cout<<maxCnt<<endl;
  }
}
/*
輸入：
4
....
....
....
X.X.
輸出：
4
*/