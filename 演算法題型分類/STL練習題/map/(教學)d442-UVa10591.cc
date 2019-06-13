// 說明 map 和 set 的查詢成本都是 ㏒N
// (v1) 單次查詢才儲存對應的值判斷有沒有重複走過 => 50ms
// (v2) 利用 DFS 概念將『所有』算過的答案都存到 map 裡面 => 35ms
// (v3) 上述可以意識到只有第一個值很大(10^9)，但第二輪開始都會落在729(9*9*9)以內，陣列建表即可 => 16ms
#include<bits/stdc++.h>
using namespace std;

vector<short> memo(730,-1);
bool IsHappy(int x,int sumD=0){
  if(memo[x]>=0) return memo[x];
  memo[x]=0; // 預設值
  for(int tmp=x; tmp; tmp/=10)
    sumD+=(tmp%10)*(tmp%10);
  return memo[x]=IsHappy(sumD);
}
int main(){
  memo[1]=1;
  for(int i=2;i<=729;i++)
    if(memo[i]==-1)
      IsHappy(i);
  int caseT, N, sumD=0;
  scanf("%d",&caseT);
  for(int caseN=1;caseN<=caseT;caseN++){
    scanf("%d",&N);
    printf("Case #%d: %d is ",caseN,N);
    for(sumD=0; N; N/=10)
      sumD+=(N%10)*(N%10);
    puts( (memo[sumD])? "a Happy number.": "an Unhappy number.");
  }
}