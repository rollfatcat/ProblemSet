// 給定Ｎ(1≤Ｎ≤5)顆骰子，求點數和Ｍ的方法數
// 動態規劃的狀態轉移作法

#include<iostream>
using namespace std;

int cnt[6][36];
int main(){
  // Pre-Process
  cnt[0][0]=1;
  for(int dice=0;dice<5;dice++)
    for(int point=dice;point<=(6*dice);point++)
      for(int i=1;i<=6;i++)
        cnt[dice+1][point+i]+=cnt[dice][point];
  // Main
  int N, M;
  while(cin>>N>>M)
    cout<<cnt[N][M]<<endl;
}