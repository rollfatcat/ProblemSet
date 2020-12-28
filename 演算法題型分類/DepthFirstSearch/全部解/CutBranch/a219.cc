#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int n, m;
bool mask[15][15];
bool canPick[15];
char bag[15], pre[15];
char alpha[15]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
void DFS(int now){
  if(now==n){
    for(int i=0;i<n;i++)
      if(bag[i]!=pre[i])
        printf("%c",bag[i]),  pre[i]=bag[i];
    printf("\n");
    return;
  }
  for(int i=0;i<n;i++)
    if(canPick[i] and !mask[now][i]){
      canPick[i]=0;
      bag[now]=alpha[i], DFS(now+1);
      canPick[i]=1;
    }
}
int main(){
  while(scanf("%d",&n)!=EOF){
    memset(mask,0,sizeof(mask));
    for(int i=0;i<n;i++)
      while(scanf("%d",&m) and m)
        mask[--m][i]=1;
    fill(canPick,canPick+15,1);
    memset(pre,'Z',sizeof(pre));
    DFS(0);
  }
}