// 矩陣連乘的DP求最小合併Cost，類似d686
#include<iostream>
using namespace std;
#define INF 0x7fffffff

int main(){
  int N, num[50], DP[50][50]={};
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>num[i];
  // Bottom-Up先建底邊
  for(int st=0,ed=2; ed<N; st++,ed++)
    DP[st][ed]=num[st]*num[st+1]*num[ed];
  for(int len=3;len<N;len++)
    for(int st=0,ed=st+len; ed<N; st++,ed++){
      DP[st][ed]=INF; // 設定極大值
      for(int mid=st+1; mid<ed; mid++){
        int sum=DP[st][mid]+DP[mid][ed]+num[st]*num[mid]*num[ed];
        if(sum>0) // 計算結果是0是沒意義的，跳開
          DP[st][ed]=min(DP[st][ed], sum);
      }
    }
  cout<<DP[0][N-1]<<endl;
}
/*  1 2 3 4 5  |  0
 *  1 3 4 5    |  6
 *  1 4 5      | 18
 *  1 5        | 38
 */