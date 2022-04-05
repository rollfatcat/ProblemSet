/* 給定Ｎ個嚴格遞增的數字組成的數列和Ｋ次查詢，輸出給定數字在數列中的位置，若不存在輸出０。
 * 解題關鍵：二分搜尋法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxK=1e5;
int N, K;
int num[MaxN+1];

int main(){
  scanf("%d %d\n",&N,&K);
  for(int i=1;i<=N;i++)
  	scanf("%d",&num[i]);
  sort(num+1,num+N+1);
  int qv, tag;
  while(K-->0){
    scanf("%d",&qv);
    tag=lower_bound(num+1,num+N+1,qv)-num;
    printf("%d\n",num[tag]==qv ? tag: 0);
  }
}