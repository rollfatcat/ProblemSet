#include<iostream>
using namespace std;
#define MaxN 16

int n;
bool ss[MaxN];
void DFS(int now){
  if(now==n){
    for(int i=0;i<n;i++)
      printf("%d",ss[i]);
    printf("\n");
    return;
  }
  ss[now]=0;
  DFS(now+1);
  ss[now]=1;
  DFS(now+1);
}
int main(){
  while(scanf("%d",&n)!=EOF)
    DFS(0);
}