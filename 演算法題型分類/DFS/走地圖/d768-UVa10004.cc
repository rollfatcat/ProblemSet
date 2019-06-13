// DFS，完成後請挑戰 ZJc889
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 200

int eNum, nNum;
bool BiFlag;
vector<int> map[MaxN];
char color[MaxN];

void DFS(int now, int clr){
  if(!BiFlag)
    return;
  color[now]=clr;
  int nxt_clr=clr^3;
  for(int i=0;i<map[now].size();i++)
    if(!color[ map[now][i] ])
      DFS(map[now][i],nxt_clr);
    else if(color[ map[now][i] ]!=nxt_clr){
        BiFlag=0;
        return;
      }
}
int main(){
  while(cin>>nNum and nNum){
    cin>>eNum;
    for(int i=0;i<nNum;i++)
      color[i]=0,  map[i].clear();

    int a, b;
    while(eNum--)
      cin>>a>>b,  map[a].push_back(b),  map[b].push_back(a);
    BiFlag=1;
    for(int i=0;i<nNum and BiFlag;i++)
      if(!color[i])
        DFS(i,1);

    if(BiFlag)
      cout<<"BICOLORABLE.\n";
    else
      cout<<"NOT BICOLORABLE.\n";

  }
}