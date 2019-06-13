// 利用 map 實現O(㏒n)查詢某個存在的值
/* 先窮舉出等式左半邊可能的值(同一個值有可能出現多次，這個次數也要記得)；
 * 再窮舉等式右邊可能的值是否有出現在左半邊。如果有出現，則將結果加上這個值在左半邊出現的次數。
 */
#include<bits/stdc++.h>
using namespace std;

int N, num[100];
int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&num[i]);
    // a*b+c=d*(f+e), d≠0
    long cnt=0, ret;
    map<int,int> memo;
    for(int a=0;a<N;a++)
      for(int b=0;b<N;b++)
        for(int c=0;c<N;c++)
          ret=num[a]*num[b]+num[c],
          (memo.find(ret)!=memo.end())? memo[ret]++: memo[ret]=1;
    for(int d=0;d<N;d++)
      if(num[d]!=0)
      for(int e=0;e<N;e++)
        for(int f=0;f<N;f++)
          ret=num[d]*(num[e]+num[f]),
          cnt+=(memo.find(ret)!=memo.end())? memo[ret]: 0;
    printf("%ld\n",cnt);
  }
}