// 遞迴式：f(n)=2*f(n-1)+2
// 觀察輸入範圍可以發現這題要實作大數加法
#include<bits/stdc++.h>
using namespace std;

const long base=1e18;
vector<long> DP[200];
int main(){
  DP[1].push_back(2);
  for(int now=2;now<=200;now++){
    long carry=2;
    for(auto n:DP[now-1])
      DP[now].push_back((n<<1)+carry),
      carry=DP[now].back()/base,  DP[now].back()%=base;
    if(carry) DP[now].push_back(carry);
  }
  for(int N; scanf("%d",&N)!=EOF;){
    printf("%ld",DP[N].back());
    for(int i=DP[N].size()-2;i>=0;i--)
      printf("%018ld",DP[N][i]);
    putchar('\n');
  }
}