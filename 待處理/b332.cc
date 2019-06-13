// 至少要挑一個數字
// 不知道錯在哪QQ
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000

long feature[MAXN+1];
long score[MAXN+1];
int main(){
  int N, P, x;
  scanf("%d%d",&N,&P);

  scanf("%d",&x);
  feature[1]=score[1]=x;
  long sumn=x;
  for(int i=2;i<=N;i++)
    scanf("%d",&x),
    feature[i]=sumn=(sumn<0)?x:sumn+x;
  score[1]=feature[1];
  score[2]=score[1]+feature[1];
  long best=score[2];
  for(int i=3;i<=N;i++)
    best=score[i]=max(best,score[i-1]+feature[i-1]);
  printf("%ld\n",max(best,score[1])%P);
}