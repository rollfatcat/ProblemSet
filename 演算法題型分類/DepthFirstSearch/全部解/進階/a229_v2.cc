// 84ms
// 本來做法是只展開一半, 當左括號數量滿的時候自動補足右括號, 但比不上一個個展開填進去= =
#include<iostream>
using namespace std;

int N;
char ss[30];
void DFS(int Ln,int Rn,int idx){
  if(Rn==N){  printf("%s\n",ss); return;  }
  if(Ln<N)  ss[idx]='(',  DFS(Ln+1,Rn,idx+1);
  if(Ln>Rn) ss[idx]=')',  DFS(Ln,Rn+1,idx+1);
}
int main(){

  while(scanf("%d",&N)!=EOF)
    ss[N<<1]='\0',
    DFS(0,0,0);
}