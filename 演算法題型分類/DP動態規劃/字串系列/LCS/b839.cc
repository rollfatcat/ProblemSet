// 複合型問題：DisjointSet+LCS，解法可以快速看出但實作細節麻煩
// LCS判斷兩者的『朋友關係』
// DisjointSet(Root查詢和最大團體人數計算)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 50

char name[50][55];
int group[50], sz[50];
int DP[2][55];

int FindRoot(int x){ return(group[x]==x)? x: group[x]=FindRoot(group[x]); }
bool BeFriend(int x,int y){
  memset(DP[1],0,sizeof(DP[1]));
  for(int i=0;i<strlen(name[x]);i++){
    int D=i&1, U=D^1;
    for(int j=0;j<strlen(name[y]);j++)
      DP[D][j+1]=(name[x][i]==name[y][j])? (DP[U][j]+1): max(DP[U][j+1],DP[D][j]);
  }
  int maxL=0, U=(strlen(name[x])-1)&1;
  for(int i=0;i<=strlen(name[y]);i++)
    maxL=max(maxL,DP[U][i]);
  return (maxL<<1)>=min(strlen(name[x]),strlen(name[y]));
}
int main(){
  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    // input and initialize
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%s",name[i]),
      group[i]=i,
      sz[i]=1;
    // 枚舉兩個人
    int max_sz=1;
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++){
        int Iroot=FindRoot(i);
        int Jroot=FindRoot(j);
        if(Iroot!=Jroot and BeFriend(i,j)){
          if(Iroot>Jroot)
            group[Iroot]=Jroot,
            sz[Jroot]+=sz[Iroot],
            max_sz=max(max_sz,sz[Jroot]);
          else
            group[Jroot]=Iroot,
            sz[Iroot]+=sz[Jroot],
            max_sz=max(max_sz,sz[Iroot]);
        }
      }
    cout<<max_sz<<'\n';
  }
}
/*
3
5
ab
bc
de
ef
abcef
5
abc
adb
xyzzzz
zzzxop
xoapd
5
abc
adb
xyzzzz
zzzxop
xoape
*/