// 類似Disjoint Set 避免重複循環導致TLE
#include<iostream>
using namespace std;

int P[21]={}, C[21];
bool vis[21]={};
int DFS(int now,int cnt){
  if(vis[now]) return cnt;
  vis[now]=1, C[P[now]]=DFS(P[now],cnt+1);
  return C[P[now]];
}
int main(){
  char ssA[21], ssB[21];
  int N, k, kC,pos;

  cin>>N;
  for(int i=1,x;i<=N;i++)
    cin>>x, P[x]=i, vis[i]=C[i]=0;
  for(int i=1;i<=N;i++)
    if(!vis[i])
      C[i]=DFS(i,0);
  scanf("%s",ssA);
  ssB[N]='\0';
  cin>>k;
  for(int i=0;i<N;i++){
    int kC=k%C[i+1], pos=i+1;
    for(int j=0;j<kC;j++)
      pos=P[pos];
    ssB[pos-1]=ssA[i];
  }
  printf("%s",ssB);
}
/*
10
8 9 5 7 10 1 2 4 6 3
as*Ittca*i
2
*/