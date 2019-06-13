// DFS暴力嘗試所有的可能路徑,找到最大權重總和
#include<iostream>
#include<cstring>
using namespace std;

int sum, maxDis;
int map[26][26];
bool vis[26];
void DFS(int now){
  if(vis[now]) return;
  if(sum>maxDis)  maxDis=sum;
  vis[now]=1;
  for(int i=0;i<26;i++)
    if(vis[i]==0 and map[now][i]>0){
      sum+=map[now][i];
      DFS(i);
      sum-=map[now][i];
    }
  vis[now]=0;
}
int main(){
  char st, a, b;
  int m, w;

  memset(map,0,sizeof(map));
  memset(vis,0,sizeof(vis));
  cin>>st>>m;
  while(m--)
    cin>>a>>b>>w, map[a-'A'][b-'A']=max(map[a-'A'][b-'A'],w);
  maxDis=sum=0;
  DFS(st-'A');
  cout<<maxDis<<endl;
}