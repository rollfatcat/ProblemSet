/* 兩兩一組，目標是最小化所有組內差距的總和
 * 解法(直覺)：排序後兩兩一組計算組內差距
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

int num[MAXN];
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&num[i]);
  sort(num,num+N);
  int sum=0;
  for(int i=1;i<N;i+=2)
    sum+=num[i]-num[i-1];
  printf("%d\n",sum);
}