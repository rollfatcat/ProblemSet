// 題目：HDU-2063
// 範例網址：https://blog.csdn.net/thunderMrbird/article/details/52231639
/* 演算法核心：有机会上，没机会创造机会也要上，難在怎麼把配對給空出來
 */
// 以下範例是最初版本(不含KM版)
#include<bits/stdc++.h>
using namespace std;

const int N=505;
vector<int>line[N];
bool used[N];// 偵測第n號女生有沒有配對給男生
int girl[N]; // 映射：girl[i]=x 第i號女生的配對男生是x
int k, m, n;
bool found(int x){
  for(auto i:line[x]){ //如果 x对i有好感且在这一个递归选取阶段没有被选取（哪怕是暂时选取，新的递归可能会换）
    if(!used[i]){
      used[i]=1; //标记被选取
      if(girl[i]==0||found(girl[i])){ //如果被选者没有归属或他的归属着可以调换（他的归属者可以选择其它被选者）
        girl[i]=x; //将归属定为 x
        //printf("%dth girl to %dth boy\n",i,x);
        return 1;
      }
    }
  }
  return 0;
}
int main(){
  while(scanf("%d",&k) and k){
    scanf("%d %d",&m,&n);
    memset(line,0,sizeof(line));
    memset(girl,0,sizeof(girl));
    for(int i=0,x,y; i<k; i++)
      scanf("%d %d",&x,&y),
      line[x].push_back(y);
    int sum=0;
    for(int i=1; i<=m; i++){
      memset(used,0,sizeof(used));
      if(found(i))
        sum++;
    }
    printf("%d\n",sum);
  }
}
/*
6 3 3
1 1
1 2
1 3
2 1
2 3
3 1

7 4 3
1 1
1 2
2 2
2 3
3 1
3 2
4 3
*/