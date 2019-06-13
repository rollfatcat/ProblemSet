// time=2.2s 不確定剪枝的方法, 最佳解是0.1s
#include<iostream>
#include<cstring>
using namespace std;

int n;
bool NoAns;
void DFS(string ss,int score,int nxt){
  if(score==n)  NoAns=false,  printf("%s\n",ss.c_str());
  if(score>=n)  return;
  DFS(ss+" + "+to_string(nxt),score+nxt,nxt+1);
  DFS(ss+" * 2",2*score,nxt);
}
int main(){
  while(scanf("%d",&n) and n){
    NoAns=true;
    DFS("1",1,2);
    if(NoAns) printf("cheat!\n");
  }
}