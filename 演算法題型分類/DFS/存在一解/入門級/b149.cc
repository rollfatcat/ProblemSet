// 輸出下一個狀態(找到一組解即可)
// Stack 沒爆開，可以直接執行

#include<iostream>
using namespace std;

int bag[10001], N, cnt;
bool use[10001]={}, fisrt=true;
void DFS(int st,int deep){
  if(deep==N+1){
    if(!cnt){
      for(int i=1;i<=N;i++)
        printf("%d ",bag[i]);
      printf("\n");
    }
    cnt--;
    fisrt=false;
    return;
  }
  for(int i=(fisrt)?bag[st]:1;i<=N;i++)
    if(!use[i]){
      use[i]=1, bag[deep]=i;
      DFS(st+1,deep+1);
      if(cnt<0) return;
      use[i]=0;
    }
}
int main(){
  scanf("%d %d",&N,&cnt);
  for(int i=1;i<=N;i++)
    scanf("%d",&bag[i]);
  DFS(1,1);
}