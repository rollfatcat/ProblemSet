// 先完成 a981之後再挑戰這題，注意輸出時方法『不可重複』
#include<bits/stdc++.h>
using namespace std;

const int MAXN=12;
bool NoANS;
int tot, N;
int number[MAXN], cnt[MAXN], bag[MAXN];
void DFS(int bag_idx,int sum,int st){
  if(sum==tot){
    NoANS=0;
    printf("%d",bag[0]);
    for(int i=1;i<bag_idx;i++)
      printf("+%d",bag[i]);
    puts("");
    return;
  }
  for(int i=st;i<N;i++){
    int k=cnt[i];
    for(;sum+k*number[i]>tot;k--);
    for(int j=0;j<k;j++)
      bag[bag_idx+j]=number[i];
    for(;k>=1;k--)
      DFS(bag_idx+k,sum+k*number[i],i+1);
  }
}
int main(){
  int allN;
  while(scanf("%d %d",&tot,&allN)!=EOF and tot){
    scanf("%d",&number[0]),
    cnt[0]=N=1;
    for(int i=1;i<allN;i++){
      scanf("%d",&number[N]);
      if(number[N]==number[N-1])
        cnt[N-1]++;
      else
        cnt[N]=1, N++;
    }
    NoANS=true;
    printf("Sums of %d:\n",tot);
    DFS(0,0,0);
    if(NoANS)
      puts("NONE");
  }
}