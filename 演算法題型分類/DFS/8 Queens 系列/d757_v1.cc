// 14 Queens
// 應該要做優化偷跑，但是沒有也可以OK，以下是未優化版本
#include<iostream>
using namespace std;

int N, cnt;
bool bitMask[14][14];
bool Lslash[27], Rslash[27], col[14];
bool *ls=&Lslash[0];  // /  範圍變化：x+y =   0 ~ 26
bool *rs=&Rslash[13]; // \  範圍變化：x-y = -13 ~ 13

void DFS(int y){
  if(y==N){
    cnt++;  return;
  }
  for(int i=0;i<N;i++)
    if(bitMask[y][i] and col[i] and ls[i+y] and rs[i-y]){
      ls[i+y]=rs[i-y]=col[i]=false;
      DFS(y+1);
      ls[i+y]=rs[i-y]=col[i]=true;
    }
}
int main(){
  string ss;
  int caseNum=1;
  while(cin>>N and N){
    for(int i=0;i<N;i++){
      cin>>ss;
      for(int j=0;j<N;j++)
        bitMask[i][j]=(ss[j]=='.');
    }
    fill(col,col+N,1);
    fill(ls,ls+2*N,1);
    fill(rs-N,rs+N,1);
    cnt=0;
    DFS(0);
    cout<<"Case "<<caseNum<<": "<<cnt<<endl;
    caseNum++;
  }
}