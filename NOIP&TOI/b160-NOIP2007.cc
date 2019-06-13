// (1)DP解，窮舉每一秒先計算只靠瞬移，再加上跑步(時間之間不互相影響)
#include<iostream>
using namespace std;
#define MaxN 300001

int DP[MaxN]={0};
int main(){
  int M, S, T, i;

  cin>>M>>S>>T;
  for(i=1;i<=T;i++){ // 計算第i秒時用瞬移的距離：DP[i]
    if(M>=10) DP[i]=DP[i-1]+60, M-=10;// 消耗魔力瞬移60m
    else      DP[i]=DP[i-1], M+=4;    // 魔力不夠就原地恢復魔力值
  }
  // 注意和上面的循环并不在一起，所以并不会影响到后面的值
  for(i=1;i<=T;i++){ // 計算同一個時間內，選擇『跑步』會不會比較好
    DP[i]=max(DP[i], DP[i-1]+17); // 如果跑步可以更遠則跑步
    if(DP[i]>=S){
      cout<<"Yes"<<endl<<i<<endl; return 0;
    }
  }
  cout<<"No"<<endl<<DP[T]<<endl;
}