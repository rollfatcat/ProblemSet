#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 100

int n, m, num[MaxN], pick[MaxN];
void DFS(int now, int from){
  if(now==m){
    printf("%d",pick[0]);
    for(int i=1;i<m;i++)
      printf(" %d",pick[i]);
    printf("\n");
    return;
  }
  for(int i=from;i<n;i++)
    pick[now]=num[i],  DFS(now+1,i+1);
}
int main(){
  while(scanf("%d",&n) and n){
    for(int i=0;i<n;i++)
      scanf("%d",&num[i]);
    sort(num,num+n);
    scanf("%d",&m);
    DFS(0,0);
    printf("\n");
  }
}